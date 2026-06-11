class Solution {
public:
    void func(vector<int>& nums, int k) {
        if(k == 0) return;
        int i = nums.size() - 1;
        while(i > 0 && nums[i] <= nums[i - 1]) {
            i--;
        }
        if(i == 0) return;
        for(int j = nums.size() - 1; j >= i; j--) {
            if(nums[j] > nums[i - 1]) {
                swap(nums[i - 1], nums[j]);
                break;
            }
        }
        reverse(nums.begin() + i, nums.end());
        func(nums, k - 1);
    }
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        func(nums, k - 1);
        string str = "";
        for(int val : nums) {
            str += to_string(val);
        }
        return str;
    }
};