Intuition

    Approach:
    1. If root is NULL or root is p or root is q then return root
    2. Find LCA in left subtree
    3. Find LCA in right subtree
    4. If both left and right are not NULL then root is the LCA
    5. If left is not NULL then left is the LCA
    6. If right is not NULL then right is the LCA
Complexity
    Time complexity:O(n)
    Space complexity:auxiliary stack space:O(h)
Code: 
    /**
     * Definition for a binary tree node.
     * struct TreeNode {
     *     int val;
     *     TreeNode *left;
     *     TreeNode *right;
     *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     * };
     */
    class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root==NULL||p==root||q==root){
                return root;
            }
            TreeNode* left=lowestCommonAncestor(root->left,p,q);
            TreeNode*  right=lowestCommonAncestor(root->right,p,q);
            if(left!=NULL&&right!=NULL){ // if both are not null then root is the LCA
                return root;
            }
            if(left!=NULL){
                return left;
            }
            return right;
        }
    };