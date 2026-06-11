class Solution {
public:
    void combinations(vector<int>& candidates, set<vector<int>>& st, vector<int> temp, int target, int i) {
        if(target == 0) {
            st.insert(temp);
            return;
        }
        if(i == candidates.size()) return;
        if(candidates[i] <= target) {
            temp.push_back(candidates[i]);
            combinations(candidates, st, temp, target - candidates[i], i + 1);
            temp.pop_back();
        }
        combinations(candidates, st, temp, target, i + 1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> st;
        vector<int> temp;
        combinations(candidates, st, temp, target, 0);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};