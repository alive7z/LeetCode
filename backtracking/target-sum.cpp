class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for(int val : nums) {
            totalSum += val;
        }
        if (abs(target) > totalSum || (totalSum - target) % 2 != 0) return 0;
        int goal = (totalSum - target) / 2;

        vector<int> prev(goal + 1, 0);
        for(int i = 0; i <= goal; i++) {
            if(nums[0] == 0 && i == 0) {
                prev[i] = 2;
                continue;
            } else if(i == 0 || nums[0] == i) {
                prev[i] = 1;
            } else {
                prev[i] = 0;
            }
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= goal; j++) {
                int pick = 0;
                if(nums[i] <= j) {
                    pick = prev[j-nums[i]];
                }
                int notPick = prev[j];
                prev[j] = pick + notPick;
            }
        }
        
        return prev[goal];
    }
};