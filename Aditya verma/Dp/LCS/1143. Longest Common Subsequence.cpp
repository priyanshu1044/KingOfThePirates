//tabulation
class Solution {
public:
    int LCS(string x ,string y, int n , int m){
        int t[n+1][m+1];
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
        return t[n][m];
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        return LCS(text1,text2,text1.length(),text2.length());
    }

};
// class Solution {
// public:
//     int t[1005][1005];    // global declaration of t
//     // memoization 
//     int LCS(string x ,string y, int n , int m){
//         if(n==0||m==0){
//             return 0;
//         }
//         if(t[n][m]!=-1){
//             return t[n][m];
//         }
//         if(x[n-1]==y[m-1]){
//             return t[n][m]= 1+LCS(x,y,n-1,m-1);
//         }
//         else{
//             return t[n][m]= max(LCS(x,y,n-1,m),LCS(x,y,n,m-1));
//         }
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         memset(t,-1,sizeof(t));
//         return LCS(text1,text2,text1.length(),text2.length());
//     }

// };


// class Solution {
// public:
//     int LCS(string x ,string y, int n , int m){
//         if(n==0||m==0){
//             return 0;
//         }
//         if(x[n-1]==y[m-1]){
//             return 1+LCS(x,y,n-1,m-1);
//         }
//         else{
//             return max(LCS(x,y,n-1,m),LCS(x,y,n,m-1));
//         }
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         return LCS(text1,text2,text1.length(),text2.length());
//     }

// };