class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int dist = 0;
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int> (n, 0));
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        int direction[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                } 
            }
        }
        while(!q.empty()) {
            int u = q.front().first.first;
            int v = q.front().first.second;
            int d = q.front().second;
            q.pop();
            for(auto itr : direction) {
                int nu = u + itr[0];
                int nv = v + itr[1];
                if(nu >= 0 && nu < m && nv >= 0 && nv < n && mat[nu][nv] == 1 && !visited[nu][nv]) {
                    visited[nu][nv] = true;
                    q.push({{nu, nv}, d + 1});
                    ans[nu][nv] = d + 1;
                }
            }
        }
        return ans;
    }
};