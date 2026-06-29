class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int curr, prev2 = nums[0], prev1 = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++) {
            int rob = nums[i] + prev2;
            int skip = 0 + prev1;
            curr = max(rob, skip);
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};