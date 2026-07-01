class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int m = nums.size();
        for(int val : nums) {
            sum += val;
        }
        if(sum % 2 != 0) return false;
        int target = sum / 2;
        vector<vector<bool>> dp(m, vector<bool> (target+1, false));

        for(int i = 0; i < m; i++) dp[i][0] = true;

        if(nums[0] <= target) dp[0][nums[0]] = true;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j <= target; j++) {
                if(i == 0) {
                    dp[i][j] = j == nums[0];
                    continue;
                }
                if(j == 0) {
                    dp[i][j] = true;
                    continue;
                }
                int pick = false;
                if(nums[i] <= j) {
                    pick = dp[i-1][j - nums[i]];
                }
                int notPick = dp[i-1][j];
                dp[i][j] = pick || notPick;
            }
        }
        return dp[m-1][target];
    }
};