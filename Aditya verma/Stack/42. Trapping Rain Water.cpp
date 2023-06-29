// on each building find max on left and right and then find min of them and subtract with current building height
// water_lvl[i]=min(left_max[i],right_max[i])-height[i];
// at last find sum of water_lvl array
// return sum of water_lvl array

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n);
        vector<int> right(n);

        int left_max=INT_MIN;
        int right_max=INT_MIN;
        left[0]=height[0];
        right[n-1]=height[n-1];

        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(left[i],right[i])-height[i];
        }
        return ans;
        

    }
};