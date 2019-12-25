//Pre-order traversal
Node* root;
q.push(root);
while(!q.empty()){
        Node* top = q.top();
        visit(top);
        q.pop();
        if(top -> right){
                q.push(right);
        }
        if(top -> left){
                q.push(left);
        }
}
//In-order traversal
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    //ptr: left most NULL child or right NULL child, which means it should go upward in the tree(next node).i.g. left upward and right upward
    //Next node is always frist left upward(either immediate or following several right upward, corresponding to left most NULL or right NULL, respectively)
    TreeNode* ptr = root;
    stack<TreeNode*> q;
    while(!q.empty() || ptr != NULL){
        if(ptr != NULL){
            q.push(ptr);
            ptr = ptr -> left;
        }
        else{
            //Next node upward
            TreeNode* top = q.top();
            ans.push_back(top -> val);
            q.pop();//Pop guarantees next to be the first left upward 
            //left upward always immediately followed by right downward
            ptr = top -> right; 
        }
    }
    return ans;   
}


