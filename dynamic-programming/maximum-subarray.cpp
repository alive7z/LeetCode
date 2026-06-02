class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i<nums.size(); i++) {
            if(sum + nums[i] < 0) {
                continue;
            } else {
                sum += nums[i];
            }
        }
        return sum;
    }
};