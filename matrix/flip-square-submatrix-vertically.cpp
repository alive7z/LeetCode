class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int a = x, b = x + k - 1;
        int st = grid[x][y], end = grid[x+k-1][y];
        while(a < b) {
            int c = y, d = y + k - 1;
            while(c <= d) {
                swap(grid[a][c], grid[b][c]);
                c++;
            }
            a++; b--;
        }
        return grid;
    }
};