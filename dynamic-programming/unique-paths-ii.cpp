class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<long long> dp(n, 0);
        
        dp[n - 1] = (obstacleGrid[m - 1][n - 1] == 0) ? 1 : 0;
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                } else if (j + 1 < n) {
                    dp[j] += dp[j + 1];
                }
            }
        }
        return (int)dp[0];
    }
};