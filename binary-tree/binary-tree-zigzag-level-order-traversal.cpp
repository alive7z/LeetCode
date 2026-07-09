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
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                temp.push_back(node->val);
                q.pop();
                if(node -> left != NULL) {
                    q.push(node -> left);
                }
                if(node -> right != NULL) {
                    q.push(node -> right);
                }
            }
            if(!flag) reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            temp.clear();
            flag = !flag;
        }
        return ans;
    }
};