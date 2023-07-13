class Solution {
public:
    
    int LCS(string x,string y,int n,int m){
        vector<vector<int>>t(n+1,vector<int>(m+1,0));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(x[i-1]==y[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[n][m];
    }
    bool isSubsequence(string s, string t) {
        if(LCS(s,t,s.length(),t.length())==s.length()){
            return true;
    }
        return false;
    }
};