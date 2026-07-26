class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return max(abs(nums[0]) * abs(nums[1]) * nums[n-1], nums[n-1] * nums[n-2] * nums[n-3]);
    }
};