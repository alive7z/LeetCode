class Solution {
public:
    int combinations(int i, int j, int m, int n) {
        if(i == m - 1 && j == n - 1) {
            return 1;
        }
        if(i >= m || j >= n) {
            return 0;
        }
        int right = combinations(i + 1, j, m, n);
        int bottom = combinations(i, j + 1, m, n);
        return right + bottom;
    }
    int uniquePaths(int m, int n) {
        return combinations(0, 0, m, n);
    }
};