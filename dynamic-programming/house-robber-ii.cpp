class Solution {
public:
    int checkParts(vector<int>& nums, int idx, int n) {
        int curr, prev2 = nums[idx], prev1 = max(nums[idx], nums[idx+1]);
        for(int i = 2 + idx; i < n; i++) {
            int rob = nums[i] + prev2;
            int skip = 0 + prev1;
            curr = max(rob, skip);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        int first = checkParts(nums, 0, n - 1);
        int second = checkParts(nums, 1, n);
        return max(first, second);

    }
};