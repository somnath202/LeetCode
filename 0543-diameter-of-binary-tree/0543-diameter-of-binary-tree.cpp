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
    int help (TreeNode* root , int & ans ){
        if(root == NULL) return 0 ;
        int l = help(root->left , ans);
        int r = help(root->right , ans);
        ans = max(ans , r+l);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        int x = help(root , ans);
        return ans ;
    }
};