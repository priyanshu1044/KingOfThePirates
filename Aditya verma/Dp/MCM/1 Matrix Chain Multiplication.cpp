class Solution{
public:
    int t[105][105];
    
    int sol(int arr[],int i,int j){
        if(i>=j){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        int minn=INT_MAX;
        int tempans;
        for(int k=i;k<=j-1;k++){
            tempans=sol(arr,i,k)+sol(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
            minn=min(minn,tempans);
        }
        return t[i][j]=minn;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(t,-1,sizeof(t));
        int i=1;    //for starting index
        int j=N-1;  //size-1
        return sol(arr,i,j);
    }

};

// int sol(int arr[],int i,int j){
//     if(i>=j){
//         return 0;
//     }
//     int minn=INT_MAX;
//     int tempans;
//     for(int k=i;k<=j-1;k++){
//         tempans=sol(arr,i,k)+sol(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
//         minn=min(minn,tempans);
//     }
//     return minn;
// }

// int matrixMultiplication(int N, int arr[])
// {
//     // code here
//     int i=1;    //for starting index
//     int j=N-1;  //size-1
//     return sol(arr,i,j);
// }