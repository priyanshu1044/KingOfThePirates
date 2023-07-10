https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int i=0,j=0;
        int n=s.length();
        if(n==0)return 0;
        int maxx=INT_MIN;
        unordered_map<char,int>mp;

        while(j<n){
            mp[s[j]]++;
            
            if(mp.size()<(j-i+1)){
                while(mp.size()<(j-i+1)&&mp.size()>0){
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                        mp.erase(s[i]);
                    i++;
                }
                j++;
            }
            if(mp.size()==(j-i+1)){
                maxx=max(maxx,j-i+1);
                j++;
            }
            if(mp.size()>(j-i+1)){
                j++;
            }
        }
        return maxx;
    }
};