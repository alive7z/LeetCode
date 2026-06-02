class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maximum = nums[0];
        int currentSum = nums[0];
        for(int i = 1; i<nums.size(); i++) {
            currentSum += nums[i];
            maximum = max(maximum, currentSum);
            if(currentSum < 0) {
                currentSum = 0;
            }
        }
        return maximum;
    }
};