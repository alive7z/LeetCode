class Solution {
public:
    bool dfs(vector<vector<int>>& grid, int i, int j, int health,
             vector<vector<vector<int>>>& dp,
             vector<vector<bool>>& visited) {

        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j])
            return false;

        health -= grid[i][j];

        if (health <= 0)
            return false;

        if (i == m - 1 && j == n - 1)
            return true;

        if (dp[i][j][health] != -1)
            return dp[i][j][health];

        visited[i][j] = true;

        bool ans = dfs(grid, i + 1, j, health, dp, visited) ||
                   dfs(grid, i - 1, j, health, dp, visited) ||
                   dfs(grid, i, j + 1, health, dp, visited) ||
                   dfs(grid, i, j - 1, health, dp, visited);

        visited[i][j] = false;

        return dp[i][j][health] = ans;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(health + 1, -1)));

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        return dfs(grid, 0, 0, health, dp, visited);
    }
};