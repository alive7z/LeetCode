class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, ans = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(count == 0) {
                ans = nums[i];
                count++;
            }
            if(nums[i] == nums[i-1]) {
                count++;
            } else {
                count--;
            }
        }
        return ans;
    }
};