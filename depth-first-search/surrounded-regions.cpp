class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        if(m < 3 || n < 3) return;
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') {
                q.push({i, 0});
                visited[i][0] = true;
            }
        }
        for(int i = 0; i < m; i++) {
            if(board[i][n-1] == 'O') {
                q.push({i, n-1});
                visited[i][n-1] = true;
            }
        }
        for(int i = 1; i < n - 1; i++) {
            if(board[0][i] == 'O') {
                q.push({0, i});
                visited[0][i] = true;;
            }
        }
        for(int i = 1; i < n - 1; i++) {
            if(board[m-1][i] == 'O') {
                q.push({m-1, i});
                visited[m-1][i] = true;
            }
        }
        int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()) {
            int u = q.front().first;
            int v = q.front().second;
            q.pop();
            for(auto itr : direction) {
                int nu = u + itr[0];
                int nv = v + itr[1];
                if(nu >= 0 && nu < m && nv >= 0 && nv < n && !visited[nu][nv] && board[nu][nv] == 'O') {
                    visited[nu][nv] = true;
                    q.push({nu, nv});
                }
            }
        }
        for(int i = 1; i < m - 1; i++) {
            for(int j = 1; j < n - 1; j++) {
                if(board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};