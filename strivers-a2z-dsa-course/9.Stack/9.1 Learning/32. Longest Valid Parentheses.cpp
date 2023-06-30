intuition:
traverse from left to right and right to left and check for valid paranthesis
in both the cases if l_count==r_count then it is valid paranthesis so update max_len
else if l_count>r_count then it is invalid paranthesis so reset l_count and r_count
else if r_count>l_count then it is invalid paranthesis so reset l_count and r_count


class Solution {
public:
    int longestValidParentheses(string s) {
        int l_count=0,r_count=0,max_len=0;
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i]=='('){
                l_count++;
            }
            else{
                r_count++;
            }
            if(l_count==r_count){
                max_len=max(max_len,l_count+r_count);
            }
            else if(r_count>l_count){   //invalid paranthesis so reset
                l_count=0;
                r_count=0;
            }
        }

        l_count=0,r_count=0;
        for (int i = s.length()-1; i >= 0; i--)
        {
            if(s[i]=='('){
                l_count++;
            }
            else{
                r_count++;
            }
            if(l_count==r_count){
                max_len=max(max_len,l_count+r_count);
            }
            else if(l_count>r_count){   //beacuse we are traversing from right to left so if l_count>r_count then it is invalid paranthesis so reset
                l_count=0;
                r_count=0;
            }
        }
        return max_len;
        
    }
};