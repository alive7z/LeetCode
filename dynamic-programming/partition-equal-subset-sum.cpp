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

        vector<bool> prev(target+1, false);

        for(int i = 0; i < m; i++) {
            vector<bool> curr(target+1, false);
            for(int j = 0; j <= target; j++) {
                if(i == 0) {
                    curr[j] = j == nums[0];
                    continue;
                }
                if(j == 0) {
                    curr[j] = true;
                    continue;
                }
                int pick = false;
                if(nums[i] <= j) {
                    pick = prev[j - nums[i]];
                }
                int notPick = prev[j];
                curr[j] = pick || notPick;
            }
            prev = curr;
        }
        return prev[target];
    }
};