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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q ;
        vector<vector<int>>ans ;
        if(root == NULL) return ans ;
        int idx = 1 ;
        q.push(root) ;
        while(!q.empty()){
            vector<int>temp;
            int size = q.size();
            for(int i = 0 ; i < size ; i++){
                TreeNode* node = q.front() ;
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                temp.push_back(node->val);
            }
            if(idx % 2 == 0) reverse(temp.begin() , temp.end());
            ans.push_back(temp);
            idx++;
        }
        return ans ;
    }
};