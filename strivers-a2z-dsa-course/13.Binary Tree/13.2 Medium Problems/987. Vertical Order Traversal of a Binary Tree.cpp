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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int ,multiset<int>>>nodes;  // {horizontal distance,{lvl,{list of node}}}
        queue<pair<TreeNode*,pair<int,int>>>que;// {node,{horizontalDistance ,lvl}}
        que.push({root,{0,0}}); 
        while(!que.empty()){
            pair<TreeNode*,pair<int,int>> p=que.front();
            que.pop();
            TreeNode* node=p.first;
            int HorizontalDistance=p.second.first; 
            int lvl=p.second.second; 
            nodes[HorizontalDistance][lvl].insert(node->val); //insert this node in the list of nodes of this horizontal distance and level
            if(node->left!=NULL) que.push({node->left,{HorizontalDistance-1,lvl+1}});
            if(node->right!=NULL) que.push({node->right,{HorizontalDistance+1,lvl+1}});
            //both case lvl is gonna increase but in left horizontal distance will decrease and in right horizontal distance will increase

        }
        vector<vector<int>>ans;
        for(auto p:nodes){
            vector<int>col;
            for(auto q:p.second){
                col.insert(col.push_back(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};