class Solution {
public:
    void sol(int open, int close,string op,vector<string>&ans){
        if(open==0&&close==0){  //base condition
            ans.push_back(op);
            return;
        }
        if(open!=0){        //we are pushing '(' for all the time till it becomes 0
            string op1=op;
            op1=op1+"(";
            sol(open-1,close,op1,ans);
        }
        if(open<close){     //we are pushing ')' only when open<close
            string op2=op;
            op2=op2+")";
            sol(open,close-1,op2,ans);
        }
        return ;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;  
        int close=n;    
        int open=n;     
        string op="";
        sol(open,close,op,ans);
        return ans;
    }
};