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
    void dfs(TreeNode* root, int i, int j, vector<pair<int, pair<int, int>>>& nodes) {
        if(root == NULL) return;
        nodes.push_back({j, {i, root->val}});
        dfs(root->left, i + 1, j - 1, nodes);
        dfs(root->right, i + 1, j + 1, nodes);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<pair<int, pair<int, int>>> nodes;
        dfs(root, 0, 0, nodes);
        sort(nodes.begin(), nodes.end());

        int currCol = nodes[0].first;

        for(auto itr : nodes) {
            if(itr.first == currCol) {
                temp.push_back(itr.second.second);
            } else {
                currCol = itr.first;
                ans.push_back(temp);
                temp.clear();
                temp.push_back(itr.second.second);
            }
        }
        ans.push_back(temp);
        return ans;
    }
};