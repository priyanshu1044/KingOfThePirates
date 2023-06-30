Explanation

if we directly check OrderTraversal it might give wrong ans
for case like :
[1,1]
[1,null,1]

Insted we check for at same time :
( if its val is same
its left is same
its right is same )
do it in recursion...

Easy code:

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
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL||q==NULL)return (p==q);
        return (p->val == q->val)&& isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};