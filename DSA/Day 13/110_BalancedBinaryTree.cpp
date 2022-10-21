/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int isHeightBal(TreeNode* root) {
        if(root == NULL) return 0;
        
        int lh = isHeightBal(root->left);
        
        int rh = isHeightBal(root->right);
        
        if(lh == -1 || rh == -1 || abs(lh - rh) > 1) return -1;
        
        return 1 + max(lh, rh);
        
    }
    bool isBalanced(TreeNode* root) {
        int ans =  isHeightBal(root);
        return ans == -1 ? false : true;
    }
};