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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> store;
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            while(q.front() != NULL) {
                TreeNode* temp = q.front();
                q.pop();
                store.push_back(temp->val);
                if(temp->left != NULL) {
                    q.push(temp->left);
                }
                if(temp->right != NULL) {
                    q.push(temp->right);
                }
            }
            if(q.size() > 1) {
                q.push(NULL);
                q.pop();
            } else q.pop();
            ans.push_back(store);
            store.clear();
        }
        return ans;
    }
};