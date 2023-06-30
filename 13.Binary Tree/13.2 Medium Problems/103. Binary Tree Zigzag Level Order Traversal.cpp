Intuition:
get vector<vector>Order; via same code for level order traversal
and now only change is that
if i is odd then we have to reverse only that sub vector in Order
and ZigZag code is ready
Code:
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
    vector<vector<int>>Order;
    vector<vector<int>> levelOrder(TreeNode*root){
        if(root==NULL)return Order;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()!=0){
            int n=q.size();
            vector<int> level;
            for(int i=0;i<n;i++){
                TreeNode*node=q.front();
                q.pop();
                level.emplace_back(node->val);
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
            }
            Order.emplace_back(level);
        }
        return Order;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        levelOrder(root);
        for(int i=0;i<Order.size();i++){
            if(i%2!=0){
                reverse(Order[i].begin(),Order[i].end());
            }
        }
        return Order;
    }
};
