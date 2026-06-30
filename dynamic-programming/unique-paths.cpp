class Solution {
public:
    int combinations(vector<vector<int>>& dp, int i, int j, int m, int n) {
        if(i == m - 1 && j == n - 1) {
            return dp[i][j] = 1;
        }
        if(i >= m || j >= n) {
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int right = combinations(dp, i + 1, j, m, n);
        int bottom = combinations(dp, i, j + 1, m, n);
        return dp[i][j] = right + bottom;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return combinations(dp, 0, 0, m, n);
    }
};