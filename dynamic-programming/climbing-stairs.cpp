class Solution {
public:
    int func(int n, vector<int>& dp) {
        if(n <= 2) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] =  func(n - 1) + func(n - 2);
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return func(n, dp);
    }
};