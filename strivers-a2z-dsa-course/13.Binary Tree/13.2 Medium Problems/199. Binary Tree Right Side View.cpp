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
    vector<vector<int>>levelOrder(TreeNode* root){
        vector<vector<int>> level_order;
        if(root==NULL) return level_order;

        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()){
            int n=que.size();
            vector<int>lvl;
            for(int i=0;i<n;i++){
                TreeNode* curr_Node=que.front();
                que.pop();
                lvl.emplace_back(curr_Node->val);
                if(curr_Node->left!=NULL)que.push(curr_Node->left);
                if(curr_Node->right!=NULL)que.push(curr_Node->right);
            }
            level_order.emplace_back(lvl);
        }
        return level_order;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        vector<vector<int>>level_order=levelOrder(root);
        int n=level_order.size();
        for(int i=0;i<n;i++){
            int m=level_order[i].size();
            ans.push_back(level_order[i][m-1]); //add last element of each level
        }
        return ans;
    }
};