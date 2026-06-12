class Solution {
public:
    bool isSafe(vector<string>& str, int row, int col, int n) {
        for(int i = 0; i < col; i++) {
            if(str[row][i] == 'Q') return false;
        }
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if(str[i][j] == 'Q') return false;
        }
        for(int i = row, j = col; i < n && j >= 0; i++, j--) {
            if(str[i][j] == 'Q') return false;
        }
        return true;
    }
    void totalCount(vector<string>& str, int n, int col, int& count) {
        if(col == n) {
            count++;
            return;
        }
        for(int row = 0; row < n; row++) {
            if(isSafe(str, row, col, n)) {
                str[row][col] = 'Q';
                totalCount(str, n, col + 1, count);
                str[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        int count = 0;
        vector<string> str(n, string(n, '.'));
        totalCount(str, n, 0, count);
        return count;
    }
};