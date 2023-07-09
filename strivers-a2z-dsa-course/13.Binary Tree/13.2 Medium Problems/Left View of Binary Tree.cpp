<vector<int>>levelOrder(Node* root){
    vector<vector<int>> level_order;
    if(root==NULL) return level_order;

    queue<Node*>que;
    que.push(root);
    while(!que.empty()){
        int n=que.size();
        vector<int>lvl;
        for(int i=0;i<n;i++){
            Node* curr_Node=que.front();
            que.pop();
            lvl.emplace_back(curr_Node->data);
            if(curr_Node->left!=NULL)que.push(curr_Node->left);
            if(curr_Node->right!=NULL)que.push(curr_Node->right);
        }
        level_order.emplace_back(lvl);
    }
    return level_order;
}
vector<int> leftView(Node* root) {
    vector<int>ans;
    vector<vector<int>>level_order=levelOrder(root);
    int n=level_order.size();
    for(int i=0;i<n;i++){
        int m=level_order[i].size();
        ans.push_back(level_order[i][0]);//add first element of each level
    }
    return ans;
}