class Solution {
public:

    bool isSafe(vector<string>& board, int row, int col, int n) {

        for(int j = 0; j < col; j++) {
            if(board[row][j] == 'Q')
                return false;
        }

        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q')
                return false;
        }

        for(int i = row, j = col; i < n && j >= 0; i++, j--) {
            if(board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void nQueens(vector<vector<string>>& res, vector<string>& board, int col, int n) {
        if(col == n) {
            res.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++) {
            if(isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                nQueens(res, board, col + 1, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        nQueens(res, board, 0, n);
        return res;
    }
};