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

    bool isEqual(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL) return p == q;
        bool leftEqual = isEqual(p -> left, q -> left);
        bool rightEqual = isEqual(p -> right, q -> right);
        return leftEqual && rightEqual && p -> val == q -> val;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL || subRoot == NULL) return root == subRoot;
        if(root -> val == subRoot -> val && isEqual(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};