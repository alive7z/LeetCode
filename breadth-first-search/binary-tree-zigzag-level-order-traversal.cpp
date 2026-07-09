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
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        vector<int> temp;
        bool flag = false;
        if(root == NULL) return {};
        ans.push_back({root->val});
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            if(q.front() == NULL && q.size() < 2) break;
            if(q.front() == NULL && q.size() > 1) {
                q.push(NULL);
                q.pop();
                if(!flag) reverse(temp.begin(), temp.end());
                ans.push_back(temp);
                temp.clear();
                flag = !flag;
                continue;
            }
            TreeNode* node = q.front();
            q.pop();
            if(node -> left != NULL) {
                temp.push_back(node->left->val);
                q.push(node -> left);
            };
            if(node -> right != NULL) {
                temp.push_back(node->right->val);
                q.push(node -> right);
            };
        }
        return ans;
    }
};