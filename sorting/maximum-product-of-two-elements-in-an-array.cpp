class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size() - 1;
        sort(nums.begin(), nums.end());
        return (nums[size] - 1) * (nums[size-1] - 1);
    }
};