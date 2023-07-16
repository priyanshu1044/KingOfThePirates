int MCM(int arr[],int i,int j){
    if(i>j){
        return 0;
    }
    for(int k=i;k<j;k++){

        //calculate tempans        
        int tempans=MCM(arr,i,k)+MCM(arr,k+1,j);

        //calculate ans
        ans<----fuc(tempans);
    }
    return ans;
}