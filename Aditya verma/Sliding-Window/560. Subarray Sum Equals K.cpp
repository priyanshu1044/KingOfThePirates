class Solution {
public:
    
    // sliding window
    int subarraySum(vector<int>& nums, int k) {
        int i=0,j=0;
        int maxx=INT_MIN;
        int n=nums.size();
        int sum=0;
        while(j<n){
            //3 conditions
            sum+=nums[j];
            if(sum<k){
                j++;
            }
            else if(sum==k){
                maxx=max(maxx,j-i+1);
                j++;    
            }
            else if(sum>k){
                while(sum>k){
                    sum-=nums[i];
                    i++;
                }
            }
            j++;
        }
        return maxx;
    }
        
        
        
//     // using map 
//     int subarraySum(vector<int>& nums, int k) {
//         map<int,int>mpp;
//         mpp[0]=1;
//         int preSum=0,cnt=0;
//         for(int i=0;i<nums.size();i++){
//             preSum=preSum+nums[i];
//             int remove=preSum-k;
//             cnt+=mpp[remove];
//             mpp[preSum]++;
//         }
//         return cnt;
//     }
    
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