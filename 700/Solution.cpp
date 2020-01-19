//Recursion
TreeNode* searchBST(TreeNode* root, int val) {
    if(root == NULL || root -> val == val) return root;
    return root -> val > val ? searchBST(root -> left, val) : searchBST(root -> right, val);
}

//Iterative
TreeNode* searchBST(TreeNode* root, int val) {
    if(root == NULL) return NULL;
    stack<TreeNode*> S;
    S.push(root);
    while(!S.empty()){
        TreeNode* top = S.top();
        S.pop();
        if(top -> val == val){
            return top;
        }
        if(top -> val > val && top -> left){
            S.push(top -> left);
        }
        if(top -> val < val && top -> right){
            S.push(top -> right);
        }            
    }
    return NULL;
}

//Don't need a stack!
TreeNode* searchBST(TreeNode* root, int val) {
    while(root && root -> val != val){
        root = root -> val < val ? root -> right : root -> left;
    }
    return root;
}
