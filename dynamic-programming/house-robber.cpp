class Solution {
public:
    int maxAmount(vector<int>& nums, vector<int>& dp, int idx) {
        if(idx == 0) return nums[idx];
        if(idx < 0) return 0;
        if(dp[idx] != -1) return dp[idx];
        int rob = nums[idx] + maxAmount(nums, dp, idx - 2);
        int skip = 0 + maxAmount(nums, dp, idx - 1);
        return dp[idx] = max(rob, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<int> dp(n + 1, -1);
        return maxAmount(nums, dp, n);
    }
};