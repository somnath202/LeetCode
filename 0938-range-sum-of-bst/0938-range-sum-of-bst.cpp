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
    int  help(TreeNode* root , int low,int high , int & ans){
        if(root == NULL) return 0;
         int l = help(root->left,low,high,ans);
         int r = help(root->right,low,high,ans);
         cout<<r<<" ";
         if(l >= low && l <= high) ans +=l ;
         if(r >= low && r <= high) ans += r ;
        return root->val ;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0 ;
        if(root==NULL) return 0 ;
        if(root->val >= low && root->val <= high) ans+= root->val ;
        int x = help(root,low,high,ans);
        return ans ;
    }
};