vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    TreeNode* ptr = root;
    TreeNode* previous = NULL;
    stack<TreeNode*> S;
    while(!S.empty() || ptr){
        if(ptr != NULL){
            S.push(ptr);
            ptr = ptr -> left;
        }
        else{
            TreeNode* top = S.top();
            //if right child is NULL, process current node and pop
            //else process right child, as long as right child is not previous, in which case it should process current node and pop
            //In comparison, using condition if previous is left child, then go to right child would miss right child since the stack
            // top may not be the immediate parent of previous visited, in case when top -> left == NULL.
            if(top -> right != previous && top -> right){
                ptr = top -> right;
            }
            //If previous is right child, process current node and pop.
            else{
                ans.push_back(top -> val);
                previous = top;
                S.pop();
            }
        }
    }
    return ans;
}

//Use two stacks, reverse pre-order means right -> left -> root. By switching left and right, we get left -> right -> root == post=order
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;
    TreeNode* ptr = root;
    stack<TreeNode*> S;
    stack<TreeNode*> out;
    S.push(ptr);
    while(!S.empty()){
        TreeNode* top = S.top();
        S.pop();
        out.push(top);
        if(top -> left){
            S.push(top -> left);
        }
        if(top -> right){
            S.push(top -> right);
        }
    }
    while(!out.empty()){
        ans.push_back(out.top() -> val);
        out.pop();
    }
    return ans;
}


