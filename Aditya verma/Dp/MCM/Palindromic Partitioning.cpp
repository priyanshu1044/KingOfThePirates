int t[501][501];

    bool isPalindrome(string s,int i,int j){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int solve(string s,int i,int j){
     //size of string
    if(i>=j){
        return 0;
    }
    if(isPalindrome(s,i,j)){
        return 0;
    }
    if(t[i][j]!=-1){
        return t[i][j];
    }
    int minn = INT_MAX;
    for(int k=i;k<=j-1;k++){
        int left,right;
        if(t[i][k]!=-1){
            left= t[i][k];
        }else{
            left=solve(s,i,k);
            t[i][k]=solve(s,i,k);
        }
        if(t[k+1][j]!=-1){
            right= t[k+1][j];
        }else{
            right=solve(s,k+1,j);
            t[k+1][j]=solve(s,k+1,j);
        }

        int tempans=1+left+right ; //1 for partitioning
        minn=min(minn,tempans);
    }
    return t[i][j]=minn;
}
int palindromicPartition(string str)
{
    // code here
        memset(t,-1,sizeof(t));

    return solve(str,0,str.length()-1);
}