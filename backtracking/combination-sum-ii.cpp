class Solution {
public:
    void combination(vector<int>& candidates, set<vector<int>>& st, vector<int> temp, int target, int idx) {
        if(target == 0) {
            st.insert(temp);
            return;
        }
        for(int i = idx; i < candidates.size(); i++) {
            while(i > idx && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] <= target) {
                temp.push_back(candidates[i]);
                combination(candidates, st, temp, target - candidates[i], i + 1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> st;
        vector<int> temp;
        combination(candidates, st, temp, target, 0);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};