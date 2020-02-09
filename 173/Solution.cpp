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
    //Pop immediately after visit
    S.pop();
    ptr = top -> right;
    while(ptr){
        S.push(ptr);
        ptr = ptr -> left;
    }
    return top -> val;
}

//Use stack of full path. Doesn't pop immediately after visit.
int next() {
    TreeNode* top = S.top();
    int result = top -> val;
    //Successor case 1: current node has right child
    if(top -> right){
        top = top -> right;
        while(top){
            S.push(top);
            top = top -> left;
        }
    }
    //Successor case 2: current node doesn't have right child
    else{
        S.pop();
        while(!S.empty() && top == S.top() -> right){
            top = S.top();
            S.pop();
        }
    }
    return result;
}


    
/** @return whether we have a next smallest number */
bool hasNext() {
    return !S.empty();
}
