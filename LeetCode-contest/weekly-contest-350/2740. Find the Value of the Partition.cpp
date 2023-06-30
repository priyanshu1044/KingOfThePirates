class Solution {
public:
    int minDiff=INT_MAX;
    
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
                int temp=abs(nums[i]-nums[i-1]);
                minDiff=min(minDiff,temp);
        }
        return minDiff;
    }
};