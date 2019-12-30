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
    if(data == "# ") return NULL;
    istringstream sin(data);
    string s;
    sin >> s;
    TreeNode* root = new TreeNode(stoi(s));
    queue<TreeNode*> bfs_q;
    bfs_q.push(root);
    while(!bfs_q.empty()){
        TreeNode* front = bfs_q.front();
        bfs_q.pop();
        sin >>s;
        if(s != "#"){
            front -> left = new TreeNode(stoi(s));
            bfs_q.push(front -> left);
        }
        sin>>s;
        if(s != "#"){
            front -> right = new TreeNode(stoi(s));
            bfs_q.push(front -> right);
        }
    }
    return root;
}
