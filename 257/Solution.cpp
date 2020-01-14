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

//Divide and Conquer
vector<string> binaryTreePaths(TreeNode* root) {
    if(root == NULL){
        return vector<string>();
    }
    if(root -> left == NULL && root -> right == NULL){
        return vector<string>(1,to_string(root -> val));
    }
    vector<string> ans;
    for(string s : binaryTreePaths(root -> left)){
        ans.push_back(to_string(root -> val) + "->" + s);
    }
    for(string s : binaryTreePaths(root -> right)){
        ans.push_back(to_string(root -> val) + "->" + s);
    }
    return ans;        
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

//Preorder
vector<string> binaryTreePaths(TreeNode* root) {
    if(root == NULL){
        return vector<string>();
    } 
    vector<string> ans;
    stack<TreeNode*> s;
    stack<string> path;
    s.push(root);
    path.push(to_string(root -> val));
    while(!s.empty()){
        TreeNode* root = s.top();
        string str_root = path.top();
        s.pop();
        path.pop();
        if(root -> left == NULL && root -> right == NULL){
            ans.push_back(str_root);
        }
        if(root -> right){
            s.push(root -> right);
            path.push(str_root + "->" + to_string(root -> right -> val));
        }
        if(root -> left){
            s.push(root -> left);
            path.push(str_root + "->" + to_string(root -> left -> val));
        }
    }
    return ans;      
}
