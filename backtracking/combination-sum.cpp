class Solution {
public:
    void combinations(vector<int>& candidates, vector<int> temp, vector<vector<int>>& ans, int i, int target) {
        if(i == candidates.size()) {
            if(target == 0) ans.push_back(temp);
            return;
        }
        if(candidates[i] <= target) {
            temp.push_back(candidates[i]);
            combinations(candidates, temp, ans, i, target - candidates[i]);
            temp.pop_back();
        }
        combinations(candidates, temp, ans, i + 1, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        combinations(candidates, temp, ans, 0, target);
        return ans;
    }
};