class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<long long> dp(n, -1e9);// Initialize with a large negative value
        dp[0] = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (-target <= nums[i] - nums[j] && nums[i] - nums[j] <= target) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        if (dp[n - 1] <0) { //simple check if the last element is negative then return -1
            return -1;
        } else {
            return dp[n - 1];
        }
    }
};