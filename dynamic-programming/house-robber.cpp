class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<int> dp(n + 1, -1);
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            int rob = INT_MIN;
            if(i > 1) {
                rob = nums[i] + dp[i - 2];
            }
            int skip = 0 + dp[i - 1];
            dp[i] = max(rob, skip);
        }
        return dp[n];
    }
};