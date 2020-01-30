//Divide and Conquer
void flatten(TreeNode* root) {
    helper(root);
}
TreeNode* helper(TreeNode* root){
    if(root == NULL) return NULL;
    if(root -> left == NULL && root -> right == NULL){ 
        return root;
    }
    TreeNode* leftLast = helper(root -> left);
    TreeNode* rightLast = helper(root -> right);
    if(leftLast){
        leftLast -> right = root -> right;
        root -> right = root -> left;
        root -> left = NULL; 
    }
    return rightLast ? rightLast : leftLast;       
}


//Preorder with recursion
//Keep track of lastNode while traversing
void flatten(TreeNode* root) {
    TreeNode* prev = NULL;
    helper(root, prev);
}    
    
void helper(TreeNode* root, TreeNode*& prev){
    if(root == NULL) return;
    if(prev){
        prev -> left = NULL;
        prev -> right = root;
    }
    prev = root;
    TreeNode* left = root -> left;
    TreeNode* right = root -> right;//Need to save right child as helper(left, prev) would update root node
    helper(left, prev);
    helper(right, prev);       
}

//Preorder traverse while building tree
void flatten(TreeNode* root) {
    if(root == NULL) return;
    stack<TreeNode*> S;
    S.push(root);
    while(!S.empty()){
        TreeNode* top = S.top();
        S.pop();
        if(top -> right){
            S.push(top -> right);
        }
        if(top -> left){
            S.push(top -> left);
        }
        if(!S.empty()){
            top -> right = S.top();
            top -> left = NULL;
        }
    }
}
