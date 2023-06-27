class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums2) {
        vector<int>ans;
        stack<int> st;
        int n = nums2.size();

        for (int i = 2*n - 1; i >= 0; i--)
        {
            if (st.empty())
            {
                ans.emplace_back(-1);
            }
            else if(st.size()>0&&st.top()>nums2[i%n]){
                ans.emplace_back(st.top());
            }

            else if(st.size()>0&&st.top()<=nums2[i%n]){
                while(st.size()>0&&st.top()<=nums2[i%n]){
                    st.pop();
                }
                if(st.empty()){
                    ans.emplace_back(-1);
                }
                else{
                    ans.emplace_back(st.top());
                }

            }

            st.push(nums2[i%n]);
        }
        reverse(ans.begin(),ans.end());
        vector<int>anss;
        for(int i=0;i<n;i++){
            anss.emplace_back(ans[i]);
        }
        return anss;
    }

};