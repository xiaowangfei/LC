//Pre-order traversal
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;
    stack<TreeNode*> S;
    S.push(root);
    while(!S.empty()){
        TreeNode* top = S.top();
        ans.push_back(top -> val);
        S.pop();
        if(top -> right){
            S.push(top -> right);
        }
        if(top -> left){
            S.push(top -> left);
        }
    }
    return ans;       
}



//In-order traversal
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    //ptr: left most NULL child or right NULL child, which means it should go upward in the tree(next node).i.g. left upward and right upward
    //Next node is always frist left upward(either immediate or following several right upward, corresponding to left most NULL or right NULL, respectively)
    TreeNode* ptr = root;
    stack<TreeNode*> S;
    while(!S.empty() || ptr != NULL){
        if(ptr != NULL){
            S.push(ptr);
            ptr = ptr -> left;
        }
        else{
            //Next node upward
            TreeNode* top = S.top();
            ans.push_back(top -> val);
            S.pop();//Pop guarantees next to be the first left upward 
            //left upward always immediately followed by right downward
            ptr = top -> right; 
        }
    }
    return ans;   
}


