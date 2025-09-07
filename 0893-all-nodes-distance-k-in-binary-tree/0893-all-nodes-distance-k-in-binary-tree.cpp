class Solution {
    // KHUD NHI HUA BKL CHUTIYA QUESTION BKL //
public:
    // Step 1: Map every node to its parent
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if (current->left) {
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }

    // Step 2: BFS from target node
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, TreeNode*> parent_track; // child -> parent
        markParents(root, parent_track); // fill parent map

        unordered_map<TreeNode*, bool> visited; // visited set
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;

        int curr_level = 0;
        while (!q.empty()) {
            int size = q.size();
            if (curr_level == K) break; // stop at distance K
            curr_level++;
            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();
                // traverse left
                if (current->left && !visited[current->left]) {
                    q.push(current->left);
                    visited[current->left] = true;
                }
                // traverse right
                if (current->right && !visited[current->right]) {
                    q.push(current->right);
                    visited[current->right] = true;
                }
                // traverse parent
                if (parent_track.find(current) != parent_track.end() && !visited[parent_track[current]]) {
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }

        vector<int> result;
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            result.push_back(current->val);
        }
        return result;
    }
};
