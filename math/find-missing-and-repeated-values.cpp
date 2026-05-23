class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, int> m;
        vector<int> ans;
        int n = grid.size();
        int sum = 0, temp;
        int total = (n * n) * ((n * n) + 1) / 2;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                int val = grid[i][j];
                m[val]++;
                sum += val;
            }
        }
        for(auto itr : m) {
            if(itr.second > 1) {
                ans.push_back(itr.first);
                temp = itr.first;
                break;
            }
        }
        sum -= temp;
        ans.push_back(total - sum);
        return ans;
    }
};