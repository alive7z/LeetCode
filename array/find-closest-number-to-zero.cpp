class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int minimum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(abs(nums[i]) < abs(minimum)) {
                minimum = nums[i];
            } else if(abs(nums[i]) == abs(minimum) && nums[i] > minimum) {
                minimum = nums[i];
            }
        }
        return minimum;
    }
};