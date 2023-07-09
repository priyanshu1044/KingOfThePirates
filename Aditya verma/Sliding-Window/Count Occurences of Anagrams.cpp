// Count Occurences of Anagrams
// https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string ptr, string s) {
	    // code here
        int k=ptr.length(); //window size
        int n=s.length();
        int i=0,j=0;
        int ans=0;
        unordered_map<char,int>mp; //map to store count of each char in ptr
        for(int i=0;i<k;i++){
            mp[ptr[i]]++;
        }
        int count=mp.size();
        while(j<n){
            //calculation for j ==> deceremet from window
            if(mp.find(s[j])!=mp.end()){    //if char is present in map then decrease its count
                mp[s[j]]--;
                if(mp[s[j]]==0) count--;    //if map's count becomes 0 then decrease count
            }
            if(j-i+1<k) j++;    //if window size is less than k then keep increasing j
            else if(j-i+1==k){  //once window size becomes equal to k
                if(count==0) ans++;
                //calculation for i  ==> increament in window
                if(mp.find(s[i])!=mp.end()){    
                    mp[s[i]]++;
                    if(mp[s[i]]==1) count++; // because map's count was 0 and now it is 1 so we have to increment count
                }
                i++;
                j++;
            }
        }
        return ans;

	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends