vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    string path =  "";
    helper(root, path, ans);
    return ans;
}
    
void helper(TreeNode* root, string path, vector<string>& ans){    
    if(root == NULL) return;
    path += to_string(root -> val);
    if(root -> left == NULL && root -> right == NULL){
        ans.push_back(path);
    }
    else{
        path += "->";
        helper(root -> left, path, ans);
        helper(root -> right, path, ans);
    }
}
