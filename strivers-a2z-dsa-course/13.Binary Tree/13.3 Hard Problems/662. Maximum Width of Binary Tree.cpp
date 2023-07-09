intuition:
1)we will use level order traversal
2)we will use pair to store node and its id //id is the position of node in that level//use on segment tree concept
3)curr_Id=que.front().second-min_Id_at_that_lvl;//to avoid overflow
4)we will use min_Id_at_that_lvl to avoid overflow
5)we will use first_Id and last_Id to calculate width of that level
6)we set all time fist_Id and last_Id && check if left child is not null then push it in queue with id=2*curr_Id+1 && check if right child is not null then push it in queue with id=2*curr_Id+2
7)we will use max function to calculate max width

complexity analysis:
time complexity:O(n)
space complexity:O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        long long width=0;
        queue<pair<TreeNode*,long long>>que;
        que.push({root,0});

        while(que.size()!=0){
            int n=que.size();
            long long min_Id=que.front().second;
            long long first_Id,last_Id;
            for(int i=0;i<n;i++){
                long long curr_Id=que.front().second-min_Id;
                TreeNode* curr_Node=que.front().first;
                que.pop();
                if(i==0){
                    first_Id=curr_Id;
                }
                if(i==n-1){
                    last_Id=curr_Id;
                }
                if(curr_Node->left!=NULL){
                    que.push({curr_Node->left,curr_Id*2+1});
                }
                if(curr_Node->right!=NULL){
                    que.push({curr_Node->right,curr_Id*2+2});
                }
            }
            width=max(width,(last_Id-first_Id+1));

        }
        return width;
    }
};