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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int , int > index;
        for(int i= 0; i< inorder.size(); i++){
            index[inorder[i]]= i;
        }
        return helper(preorder,0,inorder.size()-1,index);

    }
    int curr = 0;
    TreeNode* helper(vector<int>& preorder,int inleft,int inright ,unordered_map<int , int >& index){
        if(inleft > inright) return NULL;
        int rootval = preorder[curr++];
        TreeNode* root =  new TreeNode(rootval);
        int mid = index[rootval];
        root->left = helper(preorder,inleft,mid-1,index);
        root->right = helper(preorder,mid+1,inright,index);

        return root;
    }

};