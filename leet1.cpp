class Solution {
public:
    
    int res = INT_MAX, pre = INT_MIN;
    int minDiffInBST(TreeNode* root) {
        if (root->left) minDiffInBST(root->left);
        if (pre >= 0) res = min(res, root->val - pre);
        pre = root->val;
        if (root->right) minDiffInBST(root->right);
        return res;
    }
};
