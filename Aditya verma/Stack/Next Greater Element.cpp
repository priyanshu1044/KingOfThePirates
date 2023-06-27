class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long>ans;
        stack<long long>s;
        for (int i = n-1; i >=0; i--)
        {
            if(s.size()==0){
                ans.emplace_back(-1);
            }
            else if(s.size()>0&&s.top()>arr[i]){
                ans.emplace_back(s.top());
            }
            else if(s.size()>0&&s.top()<=arr[i]){
                while(s.size()>0&&s.top()<=arr[i]){
                    s.pop();
                }
                if(s.empty()){
                    ans.emplace_back(-1);
                }
                else{
                    ans.emplace_back(s.top());
                }

            }
            s.push(arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    // vector<long long> nextLargerElement(vector<long long> arr, int n){
    //     vector<long long>ans(n,-1);
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             if(arr[j]>arr[i]){
    //             ans[i]=arr[j];
    //             break;
    //             }
                
    //         }
    //     }
    //     return ans;
    // }
 };