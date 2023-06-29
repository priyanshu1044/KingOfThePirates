class Solution {
public:
    vector<int>NSL(vector<int>&arr){
        vector<int>left;
        set<pair<int,int>>st;
        int n=arr.size();
        int pseudo_index=-1;
        for(int i=0;i<n;i++){
            if(st.size()==0){
                left.emplace_back(pseudo_index);
            }
            else if(st.size()>0 && st.top().first<arr[i]){
                left.empalce_back(st.top().second);
            }
            else if(st.size()>0&& st.top().first>=arr[i]){
                while(st.size()>0&& st.top().first>=arr[i]){
                    st.pop();
                }
                if(st.size()==0){
                    left.emplace_back(pseudo_index);
                }
                else{
                    left.emplace_back(st.top().second);
                }
            }
            st.push({arr[i],i});
        }
        return left;
    }
    vector<int>NSR(vector<int>&arr){
        vector<int>right;
        set<pair<int,int>>st;
        int n=arr.size();
        int pseudo_index=n;
        for(int i=n-1;i>=0;i--){
            if(st.size()==0){
                right.emplace_back(pseudo_index);
            }
            else if(st.size()>0 && st.top().first<arr[i]){
                right.empalce_back(st.top().second);
            }
            else if(st.size()>0&& st.top().first>=arr[i]){
                while(st.size()>0&& st.top().first>=arr[i]){
                    st.pop();
                }
                if(st.size()==0){
                    right.emplace_back(pseudo_index);
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
    
    int MHA(vector<int>&heights){
        vector<int>right=NSR(heights);
        vector<int>left=NSL(heights);
        vector<int>width;
        int n=heights.size();
        for(int i=0;i<n;i++){
            width.emplace_back(right[i]-left[i]-1);
        }
        vector<int>area;
        for(int i=0;i<n;i++){
            area.emplace_back(width[i]*heights[i]);
        }
        return *max_element(area.begin(),area.end());
    }
    
    
    int maximalRectangle(vector<vector<char>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        vector<int>v;
        for(int j=0;j<m;j++){
            v.emplace_back(arr[0][j]-'0');
        }
        int ans=MHA(v);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(arr[i][j]=='0'){
                    v[j]=0;
                }
                else{
                    v[j]=v[j]+(arr[i][j]-'0');
                }
            }
            ans=max(ans,MHA(v));
        }
        return ans;

    }
};                              