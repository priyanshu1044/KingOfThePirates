Sliding Window Maximum
https://www.interviewbit.com/problems/sliding-window-maximum/

vector<int> Solution::slidingMaximum(const vector<int> &arr, int k) {
    int i=0;
    int j=0;
    int n=arr.size();
    vector<int>ans;
    deque<int>list;
    while(j<n){
        // calculation for j
        while(!list.empty()&&list.back()<arr[j]){
        // if the last element is smaller than the current element then pop all element 
            list.pop_back();
        }
        list.push_back(arr[j]);//push the current element

        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
            // ans.push_back(calculation);
            // slide the window
            ans.push_back(list.front());
            //calculation for i 
            // remove the element which are not part of the window
            if(list.front()==arr[i]){
                list.pop_front();
            }

            i++;
            j++;
            
        }
    }
    return ans;
}