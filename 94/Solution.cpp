//In-order traversal
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    //ptr: left most NULL child or right NULL child, which means it should go upward in the tree(next node).i.g. left upward and right upward
    //Next node is always frist left upward(either immediate or following several right upward, corresponding to left most NULL or right NULL, respectively)
    //ptr essentially keeps predecessor of current stack!
    TreeNode* ptr = root;
    stack<TreeNode*> S;
    while(!S.empty() || ptr != NULL){
        if(ptr != NULL){
            //a.Every time it push to stack, ptr to the left child.
            S.push(ptr);
            ptr = ptr -> left;
        }
        else{
            //a&b guarantees next node to be the frist left upward, which is the in-order traversal order
            TreeNode* top = S.top();
            ans.push_back(top -> val);
            S.pop();//b.pop stack right after each visit 
            //left upward always immediately followed by right downward
            ptr = top -> right; 
        }
    }
    return ans;   
}

//Use stack to kepp track the path from root to current node
vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> S;
    vector<int> ans;
    //Find minimum
    while(root){
        S.push(root);
        root = root -> left;
    }
    
    while(!S.empty()){
        TreeNode* top = S.top();
        ans.push_back(top -> val);
        //Find successor
        if(top -> right){
            root = top -> right;
            while(root){
                S.push(root);
                root = root -> left;
            }
        }
        else{
            S.pop();
            while(!S.empty() && top == S.top() -> right){
                top = S.top();
                //Only pop stack here, not right after visiting node, as previous method
                S.pop();
            }
        }       
    }        
    return ans;        
}


