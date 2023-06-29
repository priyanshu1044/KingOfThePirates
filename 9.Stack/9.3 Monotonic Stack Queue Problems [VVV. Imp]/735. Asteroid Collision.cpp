class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i=0;i<asteroids.size();i++){
            if(st.empty()|| asteroids[i]>0){
                st.push(asteroids[i]);
            }
            else{
                while (true)
                {
                    int top=st.top();
                    if(top<0){
                        st.push(asteroids[i]);
                        break;
                    }
                    else if(top==-(asteroids[i])){
                        st.pop();
                        break;
                    }
                    else if(top>-(asteroids[i])){
                        break;
                    }else{
                        st.pop();
                        if(st.empty()){
                            st.push(asteroids[i]);
                            break;
                        }
                    }
                }
                
            }
        }
        vector<int>ans;
        while(st.size()>0){
            ans.emplace_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());//LIFO so reverse //IMP
        return ans;
            
    }
};