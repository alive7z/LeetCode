class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int first = nums[0], second = -1001, third = -1001;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > first) {
                third = second;
                second = first;
                first = nums[i];
            } else if(nums[i] > second) {
                third = second;
                second = nums[i];
            } else if(nums[i] > third) {
                third = nums[i];
            } else continue;
        }
        return first * second * third;
    }
};