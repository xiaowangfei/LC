//BFS with string stream practice
// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    ostringstream sout;
    queue<TreeNode*> bfs_q;
    bfs_q.push(root);
    while(!bfs_q.empty()){
        TreeNode* front = bfs_q.front();
        if(front == NULL){
            sout<<"# ";
        }
        else{
            sout<< front -> val <<" ";
            bfs_q.push(front -> left);
            bfs_q.push(front -> right);
        }
        bfs_q.pop();
    }
    return sout.str();
}

// Decodes your encoded data to tree.
// When build a tree, it needs to first decide whether to create left/right child, before create the node and set its value.
// You can't build the tree first(creating left/right child), and then decide whether it should be NULL or set value.
// So, it has to first read the string, then create left/right child depending on the string value.
TreeNode* deserialize(string data) {
    istringstream ss(data);
    string s;
    ss >> s;
    if(s == "#") return NULL;
    TreeNode* root = new TreeNode(stoi(s));
    queue<TreeNode*> bfs_q;
    bfs_q.push(root);
    while(!bfs_q.empty()){
        TreeNode* front = bfs_q.front();
        bfs_q.pop();
        ss >>s;
        if(s != "#"){
            front -> left = new TreeNode(stoi(s));
            bfs_q.push(front -> left);
        }
        ss>>s;
        if(s != "#"){
            front -> right = new TreeNode(stoi(s));
            bfs_q.push(front -> right);
        }
    }
    return root;
}

//DFS pre-order
// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    string ans;
    dfs(root, ans);
    return ans;
}
    
void dfs(TreeNode* root, string & ans){
    if(root == NULL){
        ans += "# ";
        return;
    }
    ans += to_string(root -> val) + " ";
    dfs(root -> left, ans);
    dfs(root -> right, ans);
}
    

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    istringstream ss(data);
    string s;
    ss >> s;
    if(s == "#") return NULL;
    TreeNode* root = new TreeNode(stoi(s));
    dfs_de(root, ss);
    return root;    
}
    
void dfs_de(TreeNode* root, istringstream& ss){
    string s;
    ss >> s;
    if(s != "#"){
        root -> left = new TreeNode(stoi(s));
        dfs_de(root -> left, ss);
    }
    ss >> s;
    if(s != "#"){
        root -> right = new TreeNode(stoi(s));
        dfs_de(root -> right, ss);
    }
}

// DFS Concise version. Notes:
// 1.recursion returns desired type
// 2. As said previously, you can't build the tree first(creating left/right child), and then decide whether it should be NULL or set value.
// BUT, you can try to build the tree with fuction returning TreeNode* and decide whether to return NULL or not inside function!

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if(root == NULL) return "# ";
    return to_string(root -> val) + " " + serialize(root -> left) + serialize(root -> right);
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    istringstream ss(data);
    return dfs(ss);  
}
    
TreeNode* dfs(istringstream& ss){
    string s;
    ss >> s;
    if(s == "#"){
        return NULL;
    }
    TreeNode* new_ptr = new TreeNode(stoi(s));
    new_ptr -> left = dfs(ss);
    new_ptr -> right = dfs(ss);
    return new_ptr;
}
// Some good practice for string:
// 1.to_string(int n)
// 2.stoi(string s)
// 3.substr(int pos, int len) //len optional, otherwise return all till end
// 4.find(string "string")// return pos of first match of entire sequence, return -1 if not found
//
int helper(string& data) {
    int pos = data.find(',');
    int val = stoi(data.substr(0,pos));
    data = data.substr(pos+1);
    return val;
}
