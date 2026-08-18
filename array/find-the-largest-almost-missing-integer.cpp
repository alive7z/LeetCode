class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if(k == 0) return -1;
        if(k == 1) {
            vector<int> store(51);
            for(int val : nums) {
                store[val]++;
            }
            for(int i = 50; i >= 0; i--) {
                if(store[i] == 1) return i;
            }
            return -1;
        }
        int a = 0, b = 0;
        for(int val : nums) {
            if(val == nums[0]) a++;
            else if(val == nums[nums.size() - 1]) b++;
        }
        if(a == 1 && b > 1) return nums[0];
        if(a > 1 && b == 1) return nums[nums.size() - 1];
        return max(nums[0], nums[nums.size() - 1]);
    }
};