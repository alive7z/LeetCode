class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        queue<pair<pair<int, int>,int>> q;
        int countFresh = 0;
        int t = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, t});
                    visited[i][j] = true;
                } else if(grid[i][j] == 1) {
                    countFresh++;
                }
            }
        }
        int count = 0;
        int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()) {
            int u = q.front().first.first;
            int v = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();
            for(auto itr : direction) {
                int nu = u + itr[0];
                int nv = v + itr[1];
                if(nu >= 0 && nu < m && nv >= 0 && nv < n && !visited[nu][nv] && grid[nu][nv] == 1) {
                    visited[nu][nv] = true;
                    q.push({{nu, nv}, t+1});
                    count++;
                }
            }
        }
        if(count != countFresh) return -1;
        return time;
    }
};