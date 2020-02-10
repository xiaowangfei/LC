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
            //Pop immediately after visit top
            S.pop();
            ptr = top -> right;
        }
    }
    return ans;
}

//Use stack to kepp track the path from root to current node
vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*> S;
    vector<int> ans;
    while(root){
        ans.push_back(root -> val);
        S.push(root);
        root = root -> left;
    }
    while(!S.empty()){
        TreeNode* top = S.top();
        //Successor two cases: top has right child and not
        if(top -> right){
            top = top -> right;
            while(top){
                ans.push_back(top -> val);
                S.push(top);
                top = top -> left;
            }
        }
        else{
            S.pop();
            while(!S.empty() && top == S.top() -> right){
                top = S.top();
                S.pop();
            }
        }
    }
    return ans;               
}


