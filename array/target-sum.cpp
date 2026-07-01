class Solution {
public:
    int ways(vector<int>& nums, int target, int sum, int i) {
        if (i == 0) {
            int cnt = 0;
            if (sum + nums[0] == target) cnt++;
            if (sum - nums[0] == target) cnt++;
            return cnt;
        }
        int plus = ways(nums, target, sum + nums[i], i - 1);
        int minus = ways(nums, target, sum - nums[i], i - 1);
        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        return ways(nums, target, sum, nums.size() - 1);
    }
};