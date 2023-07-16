class Solution {
public:
    bool checkNice(string s){
        map mp;
        bool res ;
        for(int i = 0 ; i < s.length() ; i++){
            char c = s[i];
            if(isupper(c) && s.find(tolower(c)) == string:: npos)
                return false;
            else if(islower(c) && s.find(toupper(c))== string:: npos)
                return false;
        }
        return true;
    }
    string longestNiceSubstring(string s) {
        int n = s.length() , mylen = 0;
        string str = "" ,res = "";
        
        // if(s.length() == 2)
        //      if(checkNice(s))
        //          return s;
        //     else
        //         return "";
        int i=0,j=0;

        while(j<n){
            if(j-i+1<2){    // if the window size is less than 3 then just increase the window size
                str += s[j]; // and increase the frequency of the character
                j++;
            }
            else if(j-i+1==2){//when window size hits 3
                str += s[j]; // increase the frequency of the character
                if(checkNice(str) == true){
                    if(str.length() > res.length())
                        res = str;
                    mylen = j;
                }
                str.erase(0,  1);
                i++;
                j++;//slide the window
            }
            else if(j-i+1>2){
                str.erase(0,  1);
                str += s[j];
                if(checkNice(str) == true){
                    if(str.length() > res.length())
                        res = str;
                    mylen = j;
                }
                i++;
                j++;
            }
        }
            return res;

    }
};