#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxGoodLength(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        int ans = 0;

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = (A[i][j] >= 1);
                } else if (A[i][j] >= min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1) {
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                } else {
                    dp[i][j] = A[i][j];
                }
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> A(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> A[i][j];
        Solution ob;
        int ans = ob.maxGoodLength(A);
        cout << ans << endl;
    }
    return 0;
}
