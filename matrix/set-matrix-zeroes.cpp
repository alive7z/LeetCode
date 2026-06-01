class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<bool> r(row, false), c(col, false);
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(matrix[i][j] == 0) {
                    r[i] = true;
                    c[j] = true;
                }
            }
        }
        for(int i = 0; i < r.size(); i++) {
            if(r[i]) {
                for(int j = 0; j < c.size(); j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < c.size(); i++) {
            if(c[i]) {
                for(int j = 0; j < r.size(); j++) {
                    matrix[j][i] = 0;
                }
            }
        }
    }
};