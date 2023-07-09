time complexity:O(n)
space complexity:O(h)

intuition:
    we create a DFS function which takes two node as a parameter
    if both node are null then return true
    if one of them is null then return false
    if both node are not null then check for three condition
    1)check for left_node->val and right_node->val is equal or not
    2)check for left_node->left and right_node->right is equal or not beacuse they are mirror of each other
    3)check for left_node->right and right_node->left is equal or not

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
    bool dfs(TreeNode* left_node,TreeNode* right_node){
        if(left_node==NULL && right_node==NULL) return true;
        if(left_node==NULL || right_node==NULL) return false;
        //all three condition should be true
        //check for left_node->val and right_node->val is equal or not
        //check for left_node->left and right_node->right is equal or not beacuse they are mirror of each other
        //check for left_node->right and right_node->left is equal or not
        return (left_node->val==right_node->val) && 
            dfs(left_node->left,right_node->right) && 
            dfs(left_node->right,right_node->left);     
    }
    bool isSymmetric(TreeNode* root) {
        return dfs(root->left,root->right);
    }
};