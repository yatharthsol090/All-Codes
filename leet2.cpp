
class Solution {
public:
    
    int check(TreeNode *root, int &dmt) {
        if(!root) return 0;
        int lft = check(root->left, dmt);
        int rgt = check(root->right, dmt);
        dmt = max(dmt, lft+rgt);
        return max(lft, rgt) + 1;       // the left/right side maximum depth of a node will be max(lft, right) and add 1 for node to node distance. 
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int dst = 0;
        check(root, dst);
        return dst;
    }
};
