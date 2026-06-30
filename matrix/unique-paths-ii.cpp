class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int mod = (int) 2 * 1e9;
        int dp[m][n];
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) dp[i][j] = 1;
                else if(obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else {
                    int right = 0, bottom = 0;
                    if(i > 0) bottom = dp[i-1][j];
                    if(j > 0) right = dp[i][j-1];
                    dp[i][j] = bottom + right;
                }
            }
        }
        return dp[m-1][n-1] % mod;
    }
};