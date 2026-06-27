class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    while(!q.empty()) {
                        int u = q.front().first;
                        int v = q.front().second;
                        visited[u][v] = true;
                        q.pop();
                        if(u-1 >= 0 && !visited[u-1][v] && grid[u-1][v] == '1') {
                            q.push({u-1, v});
                        }
                        if(u+1 < m && !visited[u+1][v] && grid[u+1][v] == '1') {
                            q.push({u+1, v});
                        }
                        if(v-1 >= 0 && !visited[u][v-1] && grid[u][v-1] == '1') {
                            q.push({u, v-1});
                        }
                        if(v+1 < n && !visited[u][v+1] && grid[u][v+1] == '1') {
                            q.push({u, v+1});
                        }
                    }
                    count++;
                }
            }
        }
        return count;
    }
};