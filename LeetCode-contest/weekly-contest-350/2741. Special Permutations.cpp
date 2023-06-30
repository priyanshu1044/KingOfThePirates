class Solution {
public:
    int specialPerm(vector<int>& nums) {
        int ans=0;
        int MOD=1e9+7;
        for(int i=0;i<nums.size();i++){
            if (nums[i] % nums[i+1] == 0 or nums[i+1] % nums[i] == 0)
            {
                ans=ans%MOD;
            }
            
        }
        return ans;
    }
};