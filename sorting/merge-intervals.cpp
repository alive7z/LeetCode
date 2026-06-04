class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i - 1][1] >= intervals[i][0]) {
                ans.push_back({intervals[i-1][0], intervals[i][1]});
            } else {
                ans.push_back({intervals[i][0], intervals[i][1]});
            }
        }
        return ans;
    }
};