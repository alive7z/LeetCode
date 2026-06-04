class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size() < 2) return intervals;

        sort(intervals.begin(), intervals.end());

        if(intervals[0][1] >= intervals[1][0]) {
            ans.push_back({intervals[0][0], intervals[1][1]});
        } else {
            ans.push_back({intervals[1][0], intervals[1][1]});
        }

        for(int i = 2; i < intervals.size(); i++) {
            if(intervals[i - 1][1] >= intervals[i][0]) {
                ans.push_back({intervals[i-1][0], intervals[i][1]});
            } else {
                ans.push_back({intervals[i][0], intervals[i][1]});
            }
        }
        return ans;
    }
};