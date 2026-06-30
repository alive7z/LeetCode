class Solution {
public:
    int combinations(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j, int m, int n) {
        if(i >= m || j >= n) return 1e9;
        if(i == m - 1 && j == n - 1) {
            return dp[i][j] = grid[i][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = grid[i][j] + min(combinations(grid, dp, i + 1, j, m, n), combinations(grid, dp, i, j + 1, m, n));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return combinations(grid, dp, 0, 0, m, n);
    }
};