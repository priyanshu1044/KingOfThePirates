class Solution {
public:
    
    vector<int>NSL(vector<int>& arr){
        stack<pair<int,int>>st;
        vector<int>left;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(st.empty()){
                left.emplace_back(-1);
            }
            else if(st.size()>0&&st.top().first<arr[i]){
                left.emplace_back(st.top().second);
            }
            else if(st.size()>0&&st.top().first>=arr[i]){
                while(st.size()>0&&st.top().first>=arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    left.emplace_back(-1);
                }
                else{
                    left.emplace_back(st.top().second);
                }
            }
            st.push({arr[i],i});
        }
        return left;
    }
    vector<int>NSR(vector<int>& arr){
        stack<pair<int ,int>>st;
        vector<int>right;
        int n=arr.size();
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                right.emplace_back(n);
            }
            else if(st.size()>0&&st.top().first<arr[i]){
                right.emplace_back(st.top().second);
            }
			//corner case : To avoid duplication you can either change = sign to in NSL or NSR
            // you have to alter in either of one
            else if(st.size()>0&&st.top().first>=arr[i]){   //avoid dupliaction (vvvimp corner case)
                while(st.size()>0&&st.top().first>=arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    right.emplace_back(n);
                }
                else{
                    right.emplace_back(st.top().second);
                }
            }
            st.push({arr[i],i});
        }
        reverse(right.begin(),right.end());
        return right;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int ans=0;
        int MOD=1e9+7;
        vector<int>left=NSL(arr);
        vector<int>right=NSR(arr);
        for(int i=0;i<arr.size();i++){
            ans=arr[i]*(left[i]+1)*(right[i]+1)+ans;
                ans=ans%MOD;
        }
        return ans;
    }
};