//Recursion. Note the use of return value 0 to indicate none is find
int kthSmallest(TreeNode* root, int k) {
    int count = 1;
    return helper(root, k, count);
}
int helper(TreeNode* root, int k, int & count){
    if(root == NULL) return 0;
    int left = helper(root -> left, k, count);
    if(left) return left;
    if(k == count++) return root -> val;
    return helper(root -> right, k, count);        
}

//Iterative
int kthSmallest(TreeNode* root, int k) {
    int count = 1;
    TreeNode* ptr = root;
    stack<TreeNode*> S;
    while(ptr || !S.empty()){
        if(ptr){
            S.push(ptr);
            ptr = ptr -> left;
        }
        else{
            TreeNode* top = S.top();
            S.pop();
            if(k == count++){
                return top -> val;
            }
            ptr = top -> right;
        }
    }
    return 0;
}
