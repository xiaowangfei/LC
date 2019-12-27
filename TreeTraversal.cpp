//Pre-order traversal
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;
    stack<TreeNode*> S;
    S.push(root);
    while(!S.empty()){
        TreeNode* top = S.top();
        ans.push_back(top -> val);
        S.pop();
        if(top -> right){
            S.push(top -> right);
        }
        if(top -> left){
            S.push(top -> left);
        }
    }
    return ans;       
}
//Similar to In-order traversal
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    TreeNode* ptr = root;
    stack<TreeNode*> S;
    while(ptr != NULL || !S.empty()){
        if(ptr != NULL){
            ans.push_back(ptr -> val);
            if(ptr-> right)//This line is optional
                S.push(ptr);
            ptr = ptr -> left;
        }
        else{
            TreeNode* top = S.top();
            S.pop();
            ptr = top -> right;
        }
    }
    return ans;
}


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
            S.pop();//b.pop after each visit 
            //left upward always immediately followed by right downward
            ptr = top -> right; 
        }
    }
    return ans;   
}


//Morris pre-order
public List<Integer> preorderTraversal(TreeNode root) {
    LinkedList<Integer> output = new LinkedList<>();

    TreeNode node = root;
    while (node != null) {
        if (node.left == null) {
            output.add(node.val);
            node = node.right;
        }
        else {
            TreeNode predecessor = node.left;
            while ((predecessor.right != null) && (predecessor.right != node)) {
              predecessor = predecessor.right;
            }
           
            if (predecessor.right == null) {
              output.add(node.val);
              predecessor.right = node;
              node = node.left;
            }
            else{
              predecessor.right = null;
              node = node.right;
            }
        }
    }
    return output;
  }
//Morris in-order
public List<Integer> inorderTraversal(TreeNode root) {
    LinkedList<Integer> output = new LinkedList<>();

    TreeNode node = root;
    while (node != null) {
        if (node.left == null) {
            output.add(node.val);
            node = node.right;
        }
        else{
            TreeNode predecessor = node.left;
            while ((predecessor.right != null) && (predecessor.right != node)) {
                predecessor = predecessor.right;
            }

            if (predecessor.right == null) {
                predecessor.right = node;
                node = node.left;
            } else {
                predecessor.right = null;
                output.add(node.val);
                node = node.right;
            }
        }
    }
    return output;
}


