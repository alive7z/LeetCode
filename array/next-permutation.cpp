class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        if(nums.size() < 2) return;

        int i = nums.size() - 1, j = nums.size() - 1;

        if(nums[i - 1] < nums[i]) {
            swap(nums[i-1], nums[i]);
        } else {
            while(j - 1 >= 0 && nums[j] < nums[j-1]) {
                j--;
            }
            swap(nums[i], nums[j]);
            sort(nums.begin() + j, nums.end());
        }
    }
};