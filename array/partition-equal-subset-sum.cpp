class Solution {
public:
    bool combinations(vector<int>& nums, int target, int i) {
        if(i == 0) {
            if(nums[i] == target) return true;
            return false;
        }
        if(target == 0) return true;
        bool pick = false;
        if(nums[i] <= target) {
            pick = combinations(nums, target - nums[i], i - 1);
        }
        bool notPick = combinations(nums, target, i - 1);
        return pick || notPick;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int val : nums) {
            sum += val;
        }
        if(sum % 2 != 0) return false;
        int target = sum / 2;
        return combinations(nums, target, nums.size() - 1);
    }
};