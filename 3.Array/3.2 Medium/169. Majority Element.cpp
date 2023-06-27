class Solution {
public:
    
    // logical solution 
    // time complexity: O(nlogn)
    // int majorityElement(vector<int>& nums) {
    //     sort(nums.begin(),nums.end());
    //     return nums[nums.size()/2];
    // }
    
    
    // // BruteForce 
    // time complexity: O(n^2)
    // "for each element check if it is majority element or not(it appears more than n/2 times)"


    // Hashmap || Better approach
    // time complexity: O(n)
    // "use pair <element, occurence> 
    // on each iteration check if element is present in map or not and if it is present then increment its occurence "
    
    
    // Optimal Solution
    // Moore's Voting Algorithm
    // "we are taking element as majority element and then we are checking if it is actually majority element or not
    // whenever we found that element we increase count and it is not equal to that element then we decrease count
    // if count becomes 0 then we take that new element as majority element and repeat the process
    // last which ever element is stored in element var is the majority element
    // then we check if it is actually majority element or not (for our safty)"
    // time complexity: O(n)
    
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int ele;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                ele=nums[i];
            }
            if(nums[i]==ele){
                cnt++;
            }         
            else if(nums[i]!=ele){
                cnt--;
            }
        }
        int cnt1=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele){cnt1++;}
            
        }
        if(cnt1>(nums.size()/2)){
            return ele;
        }
        return -1;
    }
    

};