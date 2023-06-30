class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2!=0){
            return false;
        }
        stack <char> st;
        for(auto ch:s){
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }else if(ch==')'){
                if(st.size()==0 || st.top()!='('){
                    return false;
                }else{
                    st.pop();
                }
            }else if(ch=='}'){
                if(st.size()==0 || st.top()!='{'){
                    return false;
                }else{
                    st.pop();
                }
            }else if(ch==']'){
                if(st.size()==0 || st.top()!='['){
                    return false;
                }else{
                    st.pop();
                }
            }
        }
        retuen st.size()==0;
    }
};