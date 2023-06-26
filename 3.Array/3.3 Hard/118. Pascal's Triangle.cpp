class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        if(numRows==0)return ans;
        vector<int>first_row;
        first_row.emplace_back(1);
        ans.emplace_back(first_row);
        
        for(int i=1;i<numRows;i++){
            vector<int>pre_row=ans[i-1];
            vector<int>curr_row;
            curr_row.emplace_back(1);
            for(int j=1;j<i;j++){
                curr_row.emplace_back(pre_row[j-1]+pre_row[j]);
            }
            curr_row.emplace_back(1);
            ans.emplace_back(curr_row);
            
        }
        
        return ans;
    }
    
    
//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>>ans(numRows);
        
//         for(int i=0;i<numRows;i++){
//             ans[i].resize(i+1);
//             ans[i][0]=ans[i][i]=1;
            
//             for(int j=1;j<i;j++){
//                 ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
//             }
            
//         }
//         return ans;
        
//     }
    
    
    
//    vector<int> generateRow(int row){
//         int ans=1;
//         vector<int>temp;
//         temp.emplace_back(ans);
//         for(int i=1;i<row;i++){
//             ans=ans*(row-i);
//             ans=ans/i;
//             temp.emplace_back(ans);
//         }
//         return temp;
//     }
    
//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>>anss;
//         for(int i=1;i<=numRows;i++){
//             vector<int> temp=generateRow(i);
//             anss.emplace_back(temp);
//         }
//         return anss;
//     }
};