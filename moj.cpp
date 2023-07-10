
#include <bits/stdc++.h>
using namespace std;

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
string infixToPostfix(string s)
{
    // Your code here
    stack<char> st;
    string ans;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            ans += c;
        else if (c == '(')
            st.push('(');
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && precedence(s[i]) <= precedence(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}
void tableP(string s){
    stack<char>st;
    char temp='A';
    int n=s.length();
    cout<<"OP"<<"  s1  s2  tmp\n";
    for(int i=0;i<n;i++){
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            st.push(c);
        else{
            cout<<s[i]<<"   ";
            char sec=st.top();
            st.pop();
            char fir=st.top();
            st.pop();
            cout<<fir<<"    "<<sec<<"    "<<temp<<"\n";
            st.push(temp);
            temp++;
        }
    }
}
//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
    string s = "m=a+b*c-d/e^h";
    string op = infixToPostfix(s.substr(2, s.length()));
    op.push_back('=');
    char c = s[0];
    op = c + op;
    cout <<"suffix : "<< op<<endl;
    cout<<"table\n";
    tableP(op);
}

// } Driver Code Ends


/*
----------------------------------------------------------
ip:
m=a+b*c-d/e^h

op:
suffix : mabc*+deh^/-=
table
OP  s1  s2  tmp
*   b    c    A
+   a    A    B
^   e    h    C
/   d    C    D
-   B    D    E
=   m    E    F
*/