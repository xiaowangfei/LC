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
