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

//Use stack to keep track of the full path from root to current node
vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*> S;
    vector<int> ans;
    while(root){
        ans.push_back(root -> val);
        S.push(root);
        root = root -> left;
    }
    while(!S.empty()){
        TreeNode* top = S.top();
        //Successor two cases: top has right child and not
        if(top -> right){
            top = top -> right;
            while(top){
                ans.push_back(top -> val);
                S.push(top);
                top = top -> left;
            }
        }
        else{
            S.pop();
            while(!S.empty() && top == S.top() -> right){
                top = S.top();
                S.pop();
            }
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
            //BST successor:
            //If it has right child, find minimum in right child tree(ptr = top -> right)
            //Otherwise, find first ancestor that is a left child(stack pop)
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

//Post-order traversal
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
            //top may not be the immediate parent of previous visited, in case when top -> left == NULL.
            //A node with right child may not necessarily have a left child!(top-> left == NULL), 
            //so can't check left == previous conditon for whether go right or not!
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
//NOTE:
//a. All those if(ptr != NULL) {...} else {TreeNode* top =S.top()...}  can be replaced with 
//   while(ptr != NULL) {...} ***make sure conditon while(!S.empty() || ptr) still holds*** TreeNode* top = S.top()...
//b. For pre-order and In-order, once stack top is accessed, stack WILL pop.(node already visited), 
//   and ptr is free to set to top -> right, whether top -> right is NULL(ptr *KEEP* NULL) or not(visit right child).
//c. For post-order, set ptr to top -> right ONLY if it should visit right child next.
//   Or(!!!) after visiting right child, visit current post order node, set prev and pop.
//   -> Ptr remains prevous value, which should be NULL, so that it will find next stack top.
//   -> In fact, for post-order, after finishing node(after visiting left&right child), the only direction is to go *UP*

//Use stack to keep track of the full path from root to current node
vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*> S;
    vector<int> ans;
    while(root){
        S.push(root);
        root = root -> left;
    }
    while(!S.empty()){
        TreeNode* top = S.top();
        if(top -> right){
            top = top -> right;
            while(top){
                S.push(top);
                top = top -> left;
            }
        }
        else{
            //Add to ans when right child is NULL, keep poping & adding ans
            ans.push_back(top -> val);
            S.pop();
            while(!S.empty() && top == S.top() -> right){
                top = S.top();
                ans.push_back(top -> val);
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


