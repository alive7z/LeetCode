class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    while(!q.empty()) {
                        int u = q.front().first;
                        int v = q.front().second;
                        q.pop();
                        for(auto itr : direction) {
                            int nu = u + itr[0];
                            int nv = v + itr[1];
                            if(nu >= 0 && nu < m && nv >= 0 && nv < n && !visited[nu][nv] && grid[nu][nv] == '1') {
                                visited[nu][nv] = true;
                                q.push({nu, nv});
                            }
                        }
                    }
                    count++;
                }
            }
        }
        return count;
    }
};