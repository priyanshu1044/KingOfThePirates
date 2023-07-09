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
    void traverseLeaf(TreeNode* root, string currentPath, vector<string>& paths) {
        if (root == nullptr) {
            return;
        }
        
        // Append the current node value to the current path
        currentPath += to_string(root->val);
        
        // Check if the current node is a leaf
        if (root->left == nullptr && root->right == nullptr) {
            paths.push_back(currentPath);
            return;
        }
        
        currentPath += "->";
        
        // Traverse left and right subtrees
        traverseLeaf(root->left, currentPath, paths);
        traverseLeaf(root->right, currentPath, paths);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        
        // Check if the tree is empty
        if (root == nullptr) {
            return paths;
        }
        
        // Start traversing from the root with an empty current path
        traverseLeaf(root, "", paths);
        
        return paths;
    }
};