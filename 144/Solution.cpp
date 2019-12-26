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

//Similar to In-order traversal
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    TreeNode* ptr = root;
    stack<TreeNode*> S;
    while(ptr != NULL || !S.empty()){
        if(ptr != NULL){
            ans.push_back(ptr -> val);
            if(ptr-> right)//This line is optional
                S.push(ptr);
            ptr = ptr -> left;
        }
        else{
            TreeNode* top = S.top();
            S.pop();
            ptr = top -> right;
        }
    }
    return ans;
}

