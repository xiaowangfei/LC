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
