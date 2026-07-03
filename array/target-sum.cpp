class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for(int val : nums) {
            totalSum += val;
        }
        if((totalSum - target) % 2 != 0 || (totalSum - target) < 0) return 0;
        int goal = (totalSum - target) / 2;

        vector<vector<int>> dp(n, vector<int> (goal + 1, 0));
        for(int i = 0; i <= goal; i++) {
            if(nums[0] == 0 && i == 0) {
                dp[0][i] = 2;
                continue;
            } else if(i == 0 || nums[0] == i) {
                dp[0][i] = 1;
            } else {
                dp[0][i] = 0;
            }
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= goal; j++) {
                int pick = 0;
                if(nums[i] <= j) {
                    pick = dp[i-1][j-nums[i]];
                }
                int notPick = dp[i-1][j];
                dp[i][j] = pick + notPick;
            }
        }
        
        return dp[n-1][goal];
    }
};