class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int st = 0, mid = 0, end = nums.size() - 1;
        while(mid <= end) {
            if(nums[mid] % 2 != 0) {
                mid++;
            } else if(nums[mid] % 2 == 0) {
                swap(nums[mid], nums[st]);
                st++; mid++;
            } else {
                return nums;
            }
        }
        return nums;
    }
};