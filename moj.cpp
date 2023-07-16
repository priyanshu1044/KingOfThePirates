class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        
        // Find the dominant element in the array
        unordered_map<int, int> frequency;
        int dominant = nums[0];
        frequency[nums[0]] = 1;
        
        for (int i = 1; i < n; i++) {
            frequency[nums[i]]++;
            if (frequency[nums[i]] > frequency[dominant]) {
                dominant = nums[i];
            }
        }
        
        int left_count = 0, right_count = frequency[dominant];
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == dominant) {
                left_count++;
                right_count--;
            }
            
            if (left_count * 2 > i + 1 && right_count * 2 > n - i - 1) {
                return i;
            }
        }

        return -1;
    }
};
