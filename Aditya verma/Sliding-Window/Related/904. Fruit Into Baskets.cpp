class Solution {
public:

    int longestKSubstr(string s,int k){
        int i=0;int j=0;
        int n=s.length();
        int maxx=INT_MIN;
        unordered_map<char,int>mpp;
        while (j<n)
        {
            mpp[s[j]]++;
            if(mpp.size()<k){
                j++;
            }
            if(mpp.size()==k){
                maxx=max(maxx,j-i+1);
                j++;
            }
            if(mpp.size()>k){
                while(mpp.size()>k){
                    mpp[s[i]]--;
                    if(mpp[s[i]]==0){
                        mpp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }


        }
        if(maxx>0)
        return maxx;
        return -1;
    }
    int totalFruit(vector<int>& fruits) {
        return longestKSubstr(fruits,2);
    }
};