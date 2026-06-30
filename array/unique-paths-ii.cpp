class Solution {
public:
    int combinations(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp, int i, int j, int m, int n) {
        if(i >= m || j >= n || obstacleGrid[i][j] == 1) return 0;
        if(i == m - 1 && j == n - 1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = combinations(obstacleGrid, dp, i + 1, j, m, n) + combinations(obstacleGrid, dp, i, j + 1, m, n);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return combinations(obstacleGrid, dp, 0, 0, m, n);
    }
};