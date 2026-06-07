class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, ans;
        for(int i = 0; i < nums.size(); i++) {
            if(count == 0) {
                ans = nums[i];
                count++;
            }
            if(i > 0 && nums[i] == nums[i-1]) {
                count++;
            } else {
                count--;
            }
        }
        return ans;
    }
};