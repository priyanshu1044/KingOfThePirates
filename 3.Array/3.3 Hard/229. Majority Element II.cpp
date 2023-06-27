class Solution {
public:
    
    // BruteForce 
    // time complexity: O(n^2)
    // "for each element check if it is majority element or not(it appears more than n/3 times)"


    // Hashmap || Better approach
    // time complexity: O(n)
    // "use pair <element, occurence> 
    // on each iteration check if element is present in map or not and if it is present then increment its occurence "

    
    // vector<int> majorityElement(vector<int>& nums) {
    //     vector<int> list;
    //     map<int,int>mpp;
    //     int n=nums.size();
    //     int mini=(int)(n/3)+1;
    //     for(int i=0;i<n;i++){
    //         mpp[nums[i]]++;
    //         if(mpp[nums[i]]==mini){
    //             list.emplace_back(nums[i]);
    //         }
    //         if(list.size()==2){
    //             break;
    //         }
    //     }
    //     sort(list.begin(),list.end());
    //     return list;
    // }
    


    // Optimal Solution
    // Moore's Voting Algorithm
    // "we are taking 2 element as majority element and then we are checking if it is actually majority element or not
    // whenever we found these element we increase count of both and it is not equal to that element then we decrease count
    // if any count becomes 0 then we take that new element as majority element and repeat the process
    // last which ever element is stored in element var and declare as the majority element
    // then we check if they are actually majority elements or not (for our safty)"
    // time complexity: O(n)
    
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0;
        int ele1,ele2;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele1){
                cnt1++;
            }   
            else if(nums[i]==ele2){
                cnt2++;
            }   
            else if(cnt1==0){
                ele1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0){
                ele2=nums[i];;
                cnt2=1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        int cntt1=0,cntt2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele1){cntt1++;}
            else if(nums[i]==ele2){cntt2++;}
            
        }
        vector<int>ans;
        if(cntt1>(nums.size()/3)){
            ans.emplace_back(ele1);
        }
        if(cntt2>(nums.size()/3)){
            ans.emplace_back(ele2);
        }
        return ans;
    }
    

};