        class Solution {
        public:
            //O(n) solution
            long long subArrayRanges(vector<int>& nums) {
                long long res = 0;
                stack<int> st;
                for (int i = 0; i < nums.size(); i++) {
                    while (!st.empty() && nums[st.top()] > nums[i]) {
                        int cur = st.top();
                        st.pop();
                        int left = cur - (st.empty() ? -1 : st.top());
                        int right = i - cur;
                        res += (long long)left * right * nums[cur];
                    }
                    st.push(i);
                }
                while (!st.empty()) {
                    int cur = st.top();
                    st.pop();
                    int left = cur - (st.empty() ? -1 : st.top());
                    int right = nums.size() - cur;
                    res += (long long)left * right * nums[cur];
                }
                return res;
            }

            //brute force O(n^2)
            long long subArrayRanges(vector<int>& nums) {
                long long res = 0;
                for (int i = 0; i < nums.size(); i++) {
                    int maxx = nums[i], mini = nums[i];
                    for (int j = i; j < nums.size(); j++) {
                        maxx = max(maxx, nums[j]);
                        mini = min(mini, nums[j]);
                        res += maxx - mini;
                    }
                }
                return res;
            }

        };