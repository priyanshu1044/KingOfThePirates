class Solution {
public:
    int countGoodSubstrings(string s) {
        int i=0,j=0;
        int n=s.length();
        int count=0;
        unordered_map<char,int>mp;// this map will store the frequency of characters in the window
        while (j<n)
        {
            if(j-i+1<3){    // if the window size is less than 3 then just increase the window size
                mp[s[j]]++; // and increase the frequency of the character
                j++;
            }
            else if(j-i+1==3){//when window size hits 3
                mp[s[j]]++; // increase the frequency of the character
                if(mp.size()==3){//if the size of map is 3 then we have found a window
                    count++;
                }
                mp[s[i]]--;// now we will increase the window size
                if(mp[s[i]]==0){// if the frequency of the character becomes 0 then remove it from map
                    mp.erase(s[i]);
                }
                i++;
                j++;//slide the window
            }
        }
        return count;
    }
};