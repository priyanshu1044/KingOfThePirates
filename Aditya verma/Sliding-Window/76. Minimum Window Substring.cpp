class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(auto x:t){  // t is the pattern and store it in map
            mp[x]++;
        }
        int i=0,j=0;
        int n=s.length();
        int count=mp.size();
        int minn=INT_MAX;
        string ans="";
        while (j<n)
        {
            if(mp.find(s[j])!=mp.end()){ // if the character is present in map then decrease its count
                mp[s[j]]--;
                if(mp[s[j]]==0){    // if the count becomes 0 then decrease the count of unique characters
                    count--;
                }
            }

            if(count==0){// if count becomes 0 then we have found a window
                if(j-i+1<minn){ // if the window is smaller than the previous window then update the ans// this is the first window
                    minn=j-i+1;
                    ans=s.substr(i,minn);
                }
                while(i<=j && count==0){// now we will try to minimize the window
                    if(mp.find(s[i])!=mp.end()){// if the character is present in map then increase its count
                        mp[s[i]]++;
                        
                        if(mp[s[i]]==1){// if the count becomes 1 then increase the count of unique characters
                            if(minn>j-i+1){
                                minn=j-i+1;
                                ans=s.substr(i,minn);
                            }
                            count++;
                        }
                    }
                    i++;
                }
            }
            j++;
        }
        if(minn==INT_MAX){
            return "";
        }
        return ans;
        
    }
};