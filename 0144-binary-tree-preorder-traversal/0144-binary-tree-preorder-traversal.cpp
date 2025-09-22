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
    vector<int> preorderTraversal(TreeNode* root) {
        // vector<int> pred;
        // if(root == NULL) {
        //     return pred;
        // }
        // stack<TreeNode*> st;
        // st.push(root);
        // while(!st.empty()){
        //     root = st.top();
        //     st.pop();
        //     pred.push_back(root->val);
        //     if(root -> right != NULL){
        //         st.push(root->right);
        //     }
        //     if(root -> left != NULL){
        //         st.push(root->left);
        //     }
        // }
        // return pred;
        // Morris ->
        vector<int> ans;
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* IP = curr->left;
                while (IP->right != NULL && IP->right != curr) {
                    IP = IP->right;
                }
                if (IP->right == NULL) {
                    ans.push_back(curr->val);
                    IP->right = curr;
                    curr = curr->left;
                } else {
                    IP->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};