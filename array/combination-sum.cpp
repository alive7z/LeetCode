class Solution {
public:

    set<vector<int>> s;

    void allCombination(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& combinations, int i, int target) {
        if(i == candidates.size() || target < 0) {
            return;
        }
        if(target == 0) {
            if(s.find(combinations) == s.end()) {
                ans.push_back(combinations);
                s.insert(combinations);
            }
        }
        combinations.push_back(candidates[i]);
        allCombination(candidates, ans, combinations, i + 1, target - candidates[i]);
        allCombination(candidates, ans, combinations, i, target - candidates[i]);
        combinations.pop_back();
        allCombination(candidates, ans, combinations, i + 1, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combinations;
        allCombination(candidates, ans, combinations, 0, target);
        return ans;
    }
};