TreeNode* deleteNode(TreeNode* root, int key) {
    TreeNode* keyNode = NULL;
    TreeNode* parent = NULL;
    bool leftChild = false;
    helper(root, key, keyNode, parent, leftChild);
    TreeNode* newRoot = root;
    remove(newRoot, keyNode, parent, leftChild);
    return newRoot;
}
void helper(TreeNode* root, int key, TreeNode*& keyNode, TreeNode*& parent, bool& leftChild){
    if(root == NULL) return;
    if(root -> val == key){
        keyNode = root;
        return;
    }
    parent = root;
    if(root -> val < key){
        leftChild = false;
        helper(root -> right, key, keyNode, parent, leftChild);
    }
    else{
        leftChild = true;
        helper(root -> left, key, keyNode, parent, leftChild);
    }
}
void remove(TreeNode*& root, TreeNode* keyNode, TreeNode* parent, bool leftChild){
    if(keyNode == NULL) return;
    if(parent == NULL){
        parent = new TreeNode(-1);
        parent -> right = keyNode;
    }
    if(keyNode -> left == NULL){
        transP(parent, keyNode -> right, leftChild);
    }
    else if(keyNode -> right == NULL){
        transP(parent, keyNode -> left, leftChild);
    }
    else{
        TreeNode* successor = keyNode -> right;
        TreeNode* s_parent = keyNode;
        while(successor -> left != NULL){
            s_parent = successor;
            successor = successor -> left;
        }
        if(successor != keyNode -> right){
            transP(s_parent, successor -> right, true);
            transP(successor, keyNode -> right, false);
        }
        transP(parent, successor, leftChild);           
        successor -> left = keyNode -> left;            
    }
    if(root == keyNode){
        root = parent -> right;
    }        
}
void transP(TreeNode*& parent, TreeNode* root, bool left){
    if(left){
        parent -> left = root;
    }
    else{
        parent -> right = root;
    }
}

//Note how assigning at parent recursion level simplified logic
//Simplified:
//a.parent pointer(parent node)
//b.associated logic(left vs right)
//c.return type saves potentially another reference variable(Used on RHS of assignment)
//d.Traverse(Search) node while deleting
TreeNode* deleteNode(TreeNode* root, int key) {
    if(root == NULL) return NULL;
    if(key < root -> val){
        root -> left = deleteNode(root -> left, key);//Node
        return root;
    }
    if(key > root -> val){
        root -> right = deleteNode(root -> right, key);//Note
        return root;
    } 
    if(root -> left == NULL){
        return root -> right;
    }
    if(root -> right == NULL){
        return root -> left;
    }
    TreeNode* next = root -> right;
    TreeNode* p_next = NULL;
    while(next -> left != NULL){
        p_next = next;
        next = next -> left;
    }
    if(root -> right != next){
        p_next -> left = next -> right;
        next -> right = root -> right;
    }
    next -> left = root -> left;
    return next;    
}
