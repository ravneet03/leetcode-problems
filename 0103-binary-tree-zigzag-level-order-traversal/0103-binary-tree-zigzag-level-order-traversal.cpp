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
        vector<vector<int>> ans;
        if(root ==NULL){
            return ans;
        }
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        bool ltr = true;

        while(!nodeQueue.empty()){
            int size = nodeQueue.size();
            vector<int> row(size);
            for(int i = 0; i < size; i++){
                TreeNode* node = nodeQueue.front();
                nodeQueue.pop();
                int index;
                if(ltr){
                    index = i;
                }else{
                    index = size - 1 - i;
                }
                row[index] = node -> val;
                if(node->left) nodeQueue.push( node -> left);
                if(node->right) nodeQueue.push( node -> right );
            }
            ans.push_back(row);
            ltr = !ltr;
        }
        return ans;
    }
};