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
