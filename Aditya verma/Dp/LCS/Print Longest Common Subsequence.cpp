class Solution {
public:
    vector<vector<int>> LCS(string x,string y,int n,int m){
        vector<vector<int>> t(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(x[i-1]==y[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        return t;
    }
    
    string printSCS(string x,string y,int n,int m){//shortest common supersequence
        vector<vector<int>> t=LCS(x,y,n,m);// make a table for lcs
        
        int i=n,j=m;
        string op="";
        while(i>0&&j>0){    
            if(x[i-1]==y[j-1]){ //if equal then add one of them
                op.push_back(x[i-1]);
                i--;j--;    //move to diagonal element
            }
            else{
                if(t[i][j-1]>t[i-1][j]){//if left is greater than top then add left in op
                    op.push_back(y[j-1]);
                    j--;
                }else{  //else add top in op
                    op.push_back(x[i-1]);
                    i--;
                }
            }
        }
        while(i>0){//if any of the string is left then add it in op
            op.push_back(x[i-1]);
            i--;
        }
        while(j>0){//if any of the string is left then add it in op
            op.push_back(y[j-1]);
            j--;
        }
        //reverse the op string
        reverse(op.begin(),op.end());
        return op;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        return printSCS(str1,str2,str1.length(),str2.length());
    }
};