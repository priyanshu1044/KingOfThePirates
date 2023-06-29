// time complexity: O(n)
class Solution {
public:
    int sol(TreeNode* root,int maxx){
        if(node==NULL){
            return 0;
        }
        int lh=sol(root->left,maxx);
        int rh=sol(root->right,maxx);

        maxx=max(maxx,lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return sol(root,INT_MIN);
        
    }
};

// time complexity: O(n^2)
class Solution {
public:
    
    int TreeHeight(TreeNode* root) {
        if(root==NULL)return 0;
        return 1+max(TreeHeight(root->left),TreeHeight(root->right));
    }
    
    int maxx=INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        int lh=TreeHeight(root->left);
        int rh=TreeHeight(root->right);
        maxx=max(maxx,lh+rh);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        
        return maxx;
    }
};