//Recursion
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
//BFS1
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    if(root == NULL) return ans;
    queue<TreeNode*> bfs_q;
    queue<string> str_q;
    str_q.push(to_string(root -> val));
    bfs_q.push(root);
    while(!bfs_q.empty()){
        TreeNode* front = bfs_q.front();
        string front_str =  str_q.front();
        bfs_q.pop();
        str_q.pop();
        if(front -> left == NULL && front -> right == NULL){
            ans.push_back(front_str);
        }
        if(front -> left) {
            bfs_q.push(front -> left);
            str_q.push(front_str + "->" + to_string(front -> left -> val));
        }
        if(front -> right){
            bfs_q.push(front -> right);
            str_q.push(front_str + "->" + to_string(front -> right -> val));
        }
        
    }
    return ans;
}
//BFS2
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    if(root == NULL) return ans;
    queue<TreeNode*> bfs_q;
    map<TreeNode*, string> strmap;
    strmap[root] = "";
    bfs_q.push(root);
    while(!bfs_q.empty()){
        TreeNode* front = bfs_q.front();
        bfs_q.pop();
        if(front -> left == NULL && front -> right == NULL){
            ans.push_back(strmap[front] + to_string(front -> val));
        }
        if(front -> left) {
            bfs_q.push(front -> left);
            strmap[front -> left] = strmap[front] + to_string(front -> val) + "->";
        }
        if(front -> right){
            bfs_q.push(front -> right);
            strmap[front -> right] = strmap[front] + to_string(front -> val) + "->";
        }
        
    }
    return ans;
}
