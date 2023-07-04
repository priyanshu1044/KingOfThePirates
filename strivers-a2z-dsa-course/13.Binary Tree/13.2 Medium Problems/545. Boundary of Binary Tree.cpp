/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; 
*/
class Solution {
public:
    void traverseLeft(Node *root,vector<int>&ans){
        if((root==NULL) || (root->left==NULL&&root->right==NULL)){
            return ;
        }
        ans.emplace_back(root->data);
        if(root->left)traverseLeft(root->left,ans);
        else if(root->right)traverseLeft(root->right,ans);
    }


    void traverseLeaf(Node *root,vector<int>&ans){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL&&root->right==NULL){
            ans.emplace_back(root->data);
        }
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
    }
    
    void traverseRight(Node *root,vector<int>&ans){
        if((root==NULL)|| (root->left==NULL&&root->right==NULL)){
            return ;
        }
        if(root->right)traverseRight(root->right,ans);
        else if(root->left)traverseRight(root->left,ans);
        ans.emplace_back(root->data);
    }
    vector <int> boundary(Node *root)
    {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        ans.push_back(root->data);
        traverseLeft(root->left,ans);
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
        traverseRight(root->right,ans);
        return ans;
    }
};