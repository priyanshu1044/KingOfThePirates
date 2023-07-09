
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
    void traverseLeaf(TreeNode *root,vector<TreeNode*>&ans){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL&&root->right==NULL){
            ans.emplace_back(root);
        }
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
    }
    void getPath(TreeNode*root,vector<string>&all_path,int target){
        if(root==NULL){
            return ;
        }
        all_path.emplace_back(to_string(root->val));
        if(root->val==target){
            return ;
        }
        if(getPath(root->left,all_path,target)||
        getPath(root->right,all_path,target)){
            return ;
        }
        
        all_path.pop_back();
        return ;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> all_path;
        vector<TreeNode*>ans;
        if(root==NULL){
            return all_path;
        }
        traverseLeaf(root,ans);
        for(int i=0;i<ans.size();i++){
            getPath(root,all_path,ans[i]->val);
        }
        for(int i=0;i<all_path.size();i++){
            all_path[i]=to_string(root->val)+"->"+all_path[i];
        }
        return all_path;
    }
};

