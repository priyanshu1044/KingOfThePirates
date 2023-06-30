class Solution {
public:

    //bruteForce
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int newTarget=target-nums[i];
            for (int j = i+1; j < nums.size(); j++)
            {
                if(nums[j]==newTarget){
                    return {i,j};
                }
            }

        }
        return {-1,-1};
    }
    
    // optimal
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mpp;
        int n=nums.size();
        int remain;
        for(int i=0;i<n;i++){
            remain=target-nums[i];
            if(mpp.find(remain)!=mpp.end()){
                return {mpp[remain],i};
            }
            mpp[nums[i]]=i;
        }
        return{-1,-1};
    }
};