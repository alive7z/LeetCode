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
        vector<vector<int>> ans;
        vector<int> temp;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            if(q.front() == NULL) {
                q.pop();
                if(!q.empty()) {
                    ans.push_back(temp);
                    temp.clear();
                    q.push(NULL);
                    continue;
                }
                else {
                    ans.push_back(temp);
                    break;
                }
            }
            TreeNode* curr = q.front();
            temp.push_back(curr->val);
            q.pop();
            if(curr -> left != NULL) {
                q.push(curr -> left);
            }
            if(curr -> right != NULL) {
                q.push(curr -> right);
            }
        }
        return ans;
    }
};