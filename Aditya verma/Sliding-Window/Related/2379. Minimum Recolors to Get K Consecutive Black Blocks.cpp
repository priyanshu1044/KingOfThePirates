sliding window :
time complexity : O(n)

class Solution {
public:
    int slidingWindow(string s, int k) {
        int i=0,j=0;
        int n=s.length();
        int minn=INT_MAX;
        int w_count=0;
        while (j<n){
            if(s[j]=='W'){
                    w_count++;
            }
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                minn=min(minn,w_count);
                if(s[i]=='W'){
                    w_count--;
                }
                i++;
                j++;
            }
        }
        return minn;
    }
    
    int minimumRecolors(string blocks, int k) {
        return slidingWindow(blocks,k);
    }
};


Brute-Force :
time complexity : O(n*k)
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.length();
        int minn=INT_MAX;
        for(int i=0;i<n-k+1;i++){
            int cnt=0;
            for(int j=i;j<i+k;j++){
                if(blocks[j]=='W'){
                    cnt++;
                }
            }
            minn=min(minn,cnt);
        }
        return minn;
    }
};