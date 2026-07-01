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
    // BY USING TWO STACKS
    vector<int> postorder1(TreeNode * root){
        vector<int>ans;
        if(root == NULL) return ans ;
        stack<TreeNode *>st ;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            if(root -> left != NULL) st.push(root->left);
            if(root -> right != NULL) st.push(root->right);
            ans.push_back(root->val);
        }
        reverse(ans.begin() , ans.end());
        return ans ;

    }
    //BY USING RECURSION
    void postorder(TreeNode * root,vector<int>&ans){
        
        if(root == NULL) return;
        postorder(root->left,ans);
        postorder(root->right,ans);
        ans.push_back(root->val);
        
    }
    vector<int> postorderTraversal(TreeNode* root) {
        // vector<int>ans;
        // postorder(root,ans);
        // return ans;


        //BY USING TWO STACKS
        
        return postorder1(root);

        // BY USING SINGLE STACK



    }
};