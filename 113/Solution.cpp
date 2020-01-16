//Divide and conquer
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    if(root -> left == NULL && root -> right == NULL){
        if(sum == root -> val){
            ans.push_back(vector<int>(1, root -> val));
        }
        return ans;
    }
    for(auto path : pathSum(root -> left, sum - root -> val)){
        path.insert(path.begin(), root -> val);
        ans.push_back(path);
    }
    for(auto path : pathSum(root -> right, sum - root -> val)){
        path.insert(path.begin(), root -> val);
        ans.push_back(path);
    }
    return ans;
}

//Traverse
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> ans;
    vector<int> path;
    helper(root, sum, path, ans);
    return ans;
}
void helper(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& ans){
    if(root == NULL) return;
    path.push_back(root -> val);
    if(root -> left == NULL && root -> right == NULL && sum == root -> val){
        ans.push_back(path);
    }
    helper(root -> left, sum - root -> val, path, ans);
    helper(root -> right, sum - root -> val, path, ans);
    path.pop_back();
}
