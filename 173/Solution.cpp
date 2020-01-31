stack<TreeNode*> S;
TreeNode* ptr;
BSTIterator(TreeNode* root) {
    ptr = root;
    while(ptr){
        S.push(ptr);
        ptr = ptr -> left;
    }
}    
/** @return the next smallest number */
int next() {
    TreeNode* top = S.top();
    S.pop();
    ptr = top -> right;
    while(ptr){
        S.push(ptr);
        ptr = ptr -> left;
    }
    return top -> val;
}
    
/** @return whether we have a next smallest number */
bool hasNext() {
    return !S.empty();
}
