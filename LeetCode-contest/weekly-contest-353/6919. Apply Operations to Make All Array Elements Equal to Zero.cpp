class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        int sum = 0;

        // Calculate the sum of the first k elements
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        // Check if it's possible to make all elements zero
        if (sum % k == 0) {
            int target = sum / k;
            for (int i = k; i < n; i++) {
                sum += nums[i] - nums[i - k];  // Update the sum by sliding the window
                if (sum % k != 0 || sum / k != target) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};
