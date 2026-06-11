class Solution {
public:
    void subSets(vector<int>& nums, vector<int>& temp, set<vector<int>>& st, int i) {
        if(i == nums.size()) {
            st.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        subSets(nums, temp, st, i + 1);
        temp.pop_back();
        subSets(nums, temp, st, i + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        set<vector<int>> st;
        subSets(nums, temp, st, 0);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};