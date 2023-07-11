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
    int minDistance(string word1, string word2) {
        int lcs=LCS(word1,word2,word1.length(),word2.length());
        cout<<lcs;
        return (word1.length()-lcs+word2.length()-lcs);
    }
};