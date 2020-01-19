TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode* current = root;
    while(current != NULL){
        if(val < current -> val){
            if(current -> left){
                current = current -> left;
            }
            else{
                current -> left = new TreeNode(val);
                return root;
            }
        }
        else{
            if(current -> right){
                current = current -> right;
            }
            else{
                current -> right = new TreeNode(val);
                return root;
            }
        }
    }
    return root;        
}

//Divide and Conquer
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == NULL) return new TreeNode(val);
    if(val < root -> val){
        root -> left = insertIntoBST(root -> left, val);
    }
    else{
        root -> right = insertIntoBST(root -> right, val);
    }
    return root;        
}
