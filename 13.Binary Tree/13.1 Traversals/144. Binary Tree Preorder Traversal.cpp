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
    // void preorder(TreeNode*root, vector<int>& ans){
    //     ans.push_back(root->val);
    //     if(root->left)preorder(root->left,ans);
    //     if(root->right)preorder(root->right,ans);
    // }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     if(root==NULL) return ans;
    //     preorder(root,ans);
    //     return ans;       
    // }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        if(root==NULL) return preOrder;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            root=st.top();
            st.pop();
            preOrder.emplace_back(root->val);
            if(root->right!=NULL)st.push(root->right);
            if(root->left!=NULL)st.push(root->left);
        }
        return preOrder;       
    }
    
    
};