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
//Node how parent node's pointer is assigned to child
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == NULL) return new TreeNode(val);
    if(val < root -> val){
        //Inside parent level recursion, instead of inside child level recursion
        root -> left = insertIntoBST(root -> left, val);
    }
    else{
        root -> right = insertIntoBST(root -> right, val);
    }
    return root;        
}
