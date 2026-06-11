class Solution {
public:
    void combinations(vector<int>& candidates, vector<vector<int>>& ans, vector<int> temp, int target, int i, int sum) {
        if(i == candidates.size()) {
            if(sum == target) {
                ans.push_back(temp);
            }
            return;
        }
        if(sum + candidates[i] <= target) {
            temp.push_back(candidates[i]);
            combinations(candidates, ans, temp, target, i, sum + candidates[i]);
            temp.pop_back();
        }
        combinations(candidates, ans, temp, target, i + 1, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        combinations(candidates, ans, temp, target, 0, sum);
        return ans;
    }
};