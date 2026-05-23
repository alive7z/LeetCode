class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0' || visited[i][j] == true) {
            return;
        }
        visited[i][j] = true;
        dfs(grid, visited, i + 1, j);
        dfs(grid, visited, i - 1, j);
        dfs(grid, visited, i, j + 1);
        dfs(grid, visited, i, j - 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size(), islands = 0;
        vector<vector<bool>> visited(row, vector<bool> (col));
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, visited, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
};