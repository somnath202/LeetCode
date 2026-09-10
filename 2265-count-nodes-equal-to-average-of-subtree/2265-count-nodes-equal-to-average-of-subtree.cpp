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
    int count = 0 ;
    pair<int,int> dfs(TreeNode* root ){
        if(root == NULL){
            return {0,0};
        }

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int sum = root->val + left.first + right.first;
        int node = 1 + left.second + right.second;

        double avg = sum / node ;
        if(avg == root->val) count++;
        return {sum,node};
    }
    
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return count; 
    }
};