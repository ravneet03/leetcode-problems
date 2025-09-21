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
    int curr;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int , int> index;
        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }
        curr = postorder.size() - 1; 
        return helper(postorder, 0, inorder.size() - 1, index);
    }

    TreeNode* helper(vector<int>& postorder, int inleft, int inright, unordered_map<int , int>& index) {
        if (inleft > inright) return NULL;

        int rootval = postorder[curr--]; 
        TreeNode* root = new TreeNode(rootval);

        int mid = index[rootval];

        root->right = helper(postorder, mid + 1, inright, index);
        root->left  = helper(postorder, inleft, mid - 1, index);

        return root;
    }
};
