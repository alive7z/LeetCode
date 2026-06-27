class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int m, int n, int& count) {
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0' || visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        dfs(grid, visited, i + 1, j, m, n, count);
        dfs(grid, visited, i - 1, j, m, n, count);
        dfs(grid, visited, i, j + 1, m, n, count);
        dfs(grid, visited, i, j - 1, m, n, count);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    dfs(grid, visited, i, j, m, n, count);
                    count++;
                }
            }
        }
        return count;
    }
};