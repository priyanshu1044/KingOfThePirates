time complexity: O(n)
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }
        if(s==goal){
            unordered_map<char,int> mpp;
            for(auto i:s){
                mpp[i]++;
            }
            for(auto itr=mpp.begin(); itr!=mpp.end();itr++){
                if(itr->second>1){
                    return true;
                }
            }
            return false;
        }
        vector<int> temp_vec;
        for(int i=0; i<s.size(); i++){
            if(s[i]!=goal[i]){
                temp_vec.push_back(i);
            }
        }
        if(temp_vec.size()==2){
            if(s[temp_vec[0]]==goal[temp_vec[1]]&&s[temp_vec[1]]==goal[temp_vec[0]]){
                return true;
            }
        }
        return false;
    }

};