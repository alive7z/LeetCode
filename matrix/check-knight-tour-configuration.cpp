class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int dx[] = {1, 2, 2, 1, -2, -1, -2, -1},
            dy[] = {2, 1, -1, -2, 1, 2, -1, -2};
        int curri = 0, currj = 0, pointer = -1;
        int n = grid.size();
        if(grid[0][0]==0)pointer++;
        while (pointer < n * n) {
            bool found = false;
            for (int k = 0; k < 8; k++) {
                int ni = dx[k] + curri;
                int nj = dy[k] + currj;
                if (ni >= 0 and ni < n and nj >= 0 and nj < n and
                    grid[ni][nj] == pointer + 1) {
                    curri = ni;
                    currj = nj;
                    found = true;
                }
            }
            if (found) {
                pointer++;
            } else if (pointer != n * n - 1)
                return 0;
            else
                break;
        }
        return 1;
    }
};