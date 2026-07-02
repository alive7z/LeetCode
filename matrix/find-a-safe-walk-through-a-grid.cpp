class Solution {
public:
    bool safePath(vector<vector<int>>& grid, int health, vector<vector<int>>& visited, int i, int j, int m, int n) {
        if(i < 0 || j < 0 || i >= m || j >= n || visited[i][j]) {
            return false;
        }
        health = health - grid[i][j];
        if(health == 0) return false;
        if(i == m - 1 && j == n - 1) return true;
        visited[i][j] = true;
        bool down = safePath(grid, health, visited, i + 1, j, m, n);
        bool up = safePath(grid, health, visited, i - 1, j, m, n);
        bool right = safePath(grid, health, visited, i, j + 1, m, n);
        bool left = safePath(grid, health, visited, i, j - 1, m, n);
        visited[i][j] = false;
        return down || up || right || left;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int> (n, false));
        return safePath(grid, health, visited, 0, 0, m, n);
    }
};