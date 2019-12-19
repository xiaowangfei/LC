//DFS
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    helper(ans, root, 0);
    return ans;
}
void helper(vector<vector<int>>& V, TreeNode* node, int level){
    if(node == NULL){
        return;
    }
    if(V.size() <= level){
        V.push_back(vector<int>());
    }
    
    V[level].push_back(node -> val);
    
    helper(V, node -> left, level + 1);
    helper(V, node -> right, level + 1);    
}


//BFS
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL){
        return ans;
    }
    queue<TreeNode*> bfs_q;
    bfs_q.push(root);
    while(!bfs_q.empty()){
        int size = bfs_q.size();
        ans.push_back(vector<int>());
        for(int i = 0; i < size; i++){
            TreeNode* front = bfs_q.front();
            ans.back().push_back(front -> val);
            if(front -> left){
                bfs_q.push(front -> left);
            }
            if(front -> right){
                bfs_q.push(front -> right);
            }
            bfs_q.pop();
        }
    }
    
    return ans;
}

