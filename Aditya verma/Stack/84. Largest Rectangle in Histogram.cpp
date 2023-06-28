// for eacg building we are checking if it can be exapaned to left and right both sides
// for each building find the nearest smaller to left and nearest smaller to right
// width = right (NSR) - left (NSL) -1
// then area =  width * height




class Solution {
public:

    vector<int>NSR(vector<int>& arr){
        vector<int>right;
        int n=arr.size();
        stack<pair<int,int>>st;
        int pseudo_index=n+1;


        for(int i=n-1;i>=0;i--){
            if(st.size()==0){
                right.emplace_back(pseudo_index);
            }
            else if(st.size()>0&&st.top().first<arr[i]){
                right.emplace_back(st.top().second);
            }
            else if(st.size()>0&&st.top().first>=arr[i]){
                while(st.size()>0 && st.top().first>=arr[i]){
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


    vector<int>NSL(vector<int>& arr){
        vector<int>left;
        int n=arr.size();
        stack<pair<int,int>>st;
        int pseudo_index=-1;


        for(int i=0;i<n;i++){
            if(st.size()==0){
                left.emplace_back(pseudo_index);
            }
            else if(st.size()>0&&st.top().first<arr[i]){
                left.emplace_back(st.top().second);
            }
            else if(st.size()>0&&st.top().first>=arr[i]){
                while(st.size()>0 && st.top().first>=arr[i]){
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

    int largestRectangleArea(vector<int>& heights) {
        vector<int>right=NSR(heights);
        vector<int>left=NSL(heights);

        vector<int>width;
        for(int i=0;i<heights.size();i++){
            width.emplace_back(right[i]-left[i]-1);
        }

        vector<int>area;
        for(int i=0;i<heights.size();i++){
            area.emplace_back(width[i]*heights[i]);
        }
        return *max_element(area.begin(),area.end());
        
    }
};