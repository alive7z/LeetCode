class Solution {
public:
    int subsequence(vector<vector<unsigned long long int>>& dp, string text1, string text2, int i, int j) {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j]) {
            return dp[i][j] = 1 + subsequence(dp, text1, text2, i - 1, j - 1);
        }

        return dp[i][j] = max(subsequence(dp, text1, text2, i - 1, j), subsequence(dp, text1, text2, i, j - 1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<unsigned long long int>> dp(m, vector<unsigned long long int> (n, -1));
        return subsequence(dp, text1, text2, m - 1, n - 1);
    }
};