#include <bits/stdc++.h> 

int LCStr(string &x,string &y,int n,int m){
    int t[n+1][m+1];
    for (int i = 0; i < n+1; i++){
        for (int j = 0; j < m+1; j++){
            if(i==0||j==0){
                t[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1]==y[j-1]){
                t[i][j]=1+t[i-1][j-1];//if char is matched then add 1 to the diagonal element
            }
            else{
                t[i][j]=0;//if discontinuity is not allowed then put 0 here
            }
        }
    }
    //t[n][m] will not always gives the length of the longest common substring
    //we have to traverse the whole matrix to find the max element in the matrix
	int maxx=INT_MIN;//find the max element in the matrix
	for(int i=0;i<n+1;i++){
		for(int j=0;j<m+1;j++){
			maxx=max(maxx,t[i][j]);
		}
	}
    return maxx;
}
int lcs(string &str1, string &str2){
	//	Write your code here.
    return LCStr(str1,str2,str1.length(),str2.length());
}