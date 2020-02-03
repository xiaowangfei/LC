int closestValue(TreeNode* root, double target) {
    //To handle closest or similar cases. Either a.set flag about whether updated b.Use first element value(root -> val in this case)
    int closest = root -> val;
    while(root){
        //For BST, you can you ptr to go down instead of recursion
        closest = abs(root -> val - target) < abs(closest - target) ? root -> val : closest;
        root = target < root -> val ? root -> left : root -> right;           
    }
    return closest;
}
