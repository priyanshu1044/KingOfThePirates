// 560. Subarray Sum Equals K
// 


class Solution {
public:
    
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mpp;
        mpp[0]=1;
        int preSum=0,cnt=0;
        
        for(int i=0;i<nums.size();i++){
            preSum=preSum+nums[i];
            int remove=preSum-k;
            cnt+=mpp[remove];
            mpp[preSum]++;
            
        }
        return cnt;
    }
    
//  // Brute Force approach 
//     int subarraySum(vector<int>& nums, int k) {
//         int n=nums.size();
//         int count=0;
//         for(int i=0;i<n;i++){
//             int sum=0;
//             for(int j=i;j<n;j++){
//                 sum+=nums[j];
//                 if(sum==k){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }

};