// First negative integer in every window of size k
// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

vector<long long> printFirstNegativeInteger(long long int arr[],long long int N, long long int k) {

    // code here


    vector<long long>ans;
    long long i=0,j=0;

    queue<long long>list;
    while(j<N){
        if(arr[j]<0) //if negative then push it to list
            list.push(arr[j]);
        if(j-i+1<k) j++; //if window size is less than k then keep increasing j
        else if(j-i+1==k){
            if(list.size()==0){
                ans.emplace_back(0);
            }
            else{
                ans.emplace_back(list.front());
                if(arr[i]==list.front()) list.pop();
            }
            i++;
            j++;
        }
    }
    return ans;
                                                 
 }