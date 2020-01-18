void flatten(TreeNode* root) {
    helper(root);
}
TreeNode* helper(TreeNode* root){
    if(root == NULL) return NULL;
    if(root -> left == NULL && root -> right == NULL){ 
        return root;
    }
    if(root -> left){
        helper(root -> left) -> right = root -> right;
        root -> right = root -> left;
        root -> left = NULL; 
    }
    return helper(root -> right);
}
    
void flatten(TreeNode* root) {
    helper(root);
}
TreeNode* helper(TreeNode* root){
    if(root == NULL) return NULL;
    if(root -> left == NULL && root -> right == NULL){ 
        return root;
    }
    TreeNode* RightMost = helper(root -> right);
    TreeNode* LeftMost = helper(root -> left);
    if(LeftMost){
        LeftMost -> right = root -> right;
        root -> right = root -> left;
        root -> left = NULL; 
    }
    return RightMost?RightMost : LeftMost;       
}
