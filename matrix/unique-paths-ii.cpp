class Solution {
public:
    int combinations(vector<vector<int>>& obstacleGrid, int i, int j, int m, int n) {
        if(i >= m || j >= n || obstacleGrid[i][j] == 1) return 0;
        if(i == m - 1 && j == n - 1) return 1;
        return combinations(obstacleGrid, i + 1, j, m, n) + combinations(obstacleGrid, i, j + 1, m, n);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return combinations(obstacleGrid, 0, 0, m, n);
    }
};