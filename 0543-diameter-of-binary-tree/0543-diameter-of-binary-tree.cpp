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

private:
    int maxDepth(TreeNode* root, int& maxi) {
        if(root == NULL) return 0;
         int l = maxDepth(root -> left, maxi);
         int r = maxDepth(root -> right, maxi);
         maxi = max((l+r), maxi);
         return 1+ max(l,r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        int maxi = INT_MIN;
        maxDepth(root,maxi);
        return maxi;
    }
};