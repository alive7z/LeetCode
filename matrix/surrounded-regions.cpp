class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        if(m < 3 || n < 3) return;
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') {
                q.push({i, 0});
            }
        }
        for(int i = 0; i < m; i++) {
            if(board[i][n-1] == 'O') {
                q.push({i, n-1});
            }
        }
        for(int i = 1; i < n - 1; i++) {
            if(board[0][i] == 'O') {
                q.push({0, i});
            }
        }
        for(int i = 1; i < n - 1; i++) {
            if(board[m-1][i] == 'O') {
                q.push({m-1, i});
            }
        }
        int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()) {
            int u = q.front().first;
            int v = q.front().second;
            board[u][v] = 'Z';
            q.pop();
            for(auto itr : direction) {
                int nu = u + itr[0];
                int nv = v + itr[1];
                if(nu >= 0 && nu < m && nv >= 0 && nv < n && board[nu][nv] != 'Z' && board[nu][nv] == 'O') {
                    q.push({nu, nv});
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if(board[i][j] == 'Z') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};