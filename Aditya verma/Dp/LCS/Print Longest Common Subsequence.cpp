vector<vector<int>> LCS(string x ,string y, int n , int m){
    vector<vector<int>>t(n+1,vector<int>(m+1));

    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < m+1; j++)
        {
            if(i==0||j==0){
                t[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1]==y[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    return t;
}
string printLCS(string &x, string &y,int n, int m){
    // Write your code here.	
    vector<vector<int>>t=LCS(x,y,n,m);
    int i=n,j=m;
    string op="";
    while(i>0&&j>0){
        if(x[i-1]==y[j-1]){
            op.push_back(x[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i][j-1]>t[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }
    }
    reverse(op.begin(),op.end());
    return op;
}

string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.
    return printLCS(s1,s2,n,m);	
}