class Solution {
public:

    // Optimal: O(n^2) || two pointer approach
    vector<vector<int>> threeSum(vector<int>& nums) {

    vector<vector<int>>ans;
    sort(nums.begin(),nums.end());

    for (int i = 0; i < nums.size; i++)
    {
        if(i>0&&nums[i]==nums[i-1])continue;
        int j=i+1;
        int k=nums.size()-1;
        while (j<k)
        {
            int sum=nums[i]+nums[j]+nums[k];
            if(sum<0){
                j++;
            }
            else if(sum>0){
                k--;
            }else{
                vector<int>temp={nums[i],nums[j],nums[k]};
                ans.emplace_back(temp);
                j++;
                k--;
                while(j<k&&nums[j]==nums[j-1])j++;
                while(j<k&&nums[k]==nums[k+1])k--;
            }
        }
        
    }
    

    return ans; 
    }




    better solution || hashset || O(n^2)

    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>s;
        for(int i=0;i<nums.size();i++){
            set<int>hashset;
            for (int j = i+1; j < nums.size(); j++){
                int third=-nums[i]-nums[j];
                if(hashset.find(third)!=hashset.end()){
                    vector<int>temp={nums[i],nums[j],third};
                    sort(temp.begin(),temp.end());
                    s.insert(temp);
                }
                hashset.insert(nums[j]);
            }
            
        }
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }





    Brute Force:
    lets try out all the possible triplets and check if they are equal to zero or not.
    Notice that the solution set must not contain duplicate triplets.
    Time Complexity: O(n^3)
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>s;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int>temp={nums[i],nums[j],nums[k]};
                        sort(temp.begin(),temp.end());
                        s.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }


    
    
    
};