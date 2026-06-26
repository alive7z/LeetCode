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
    void minimum(int& prev, int& mini, TreeNode* root) {
        if(root == NULL) {
            return;
        }
        minimum(prev, mini, root -> left);
        if(prev != -1) {
            mini = min(mini, (root->val) - prev);
        }
        prev = root->val;
        minimum(prev, mini, root -> right);
    }
    int minDiffInBST(TreeNode* root) {
        int prev = -1, mini = INT_MAX;
        minimum(prev, mini, root);
        return mini;
    }
};