class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1;
        while(st <= end) {
            int mid = st + (end-st)/2;
            if(nums[mid] == target) {
                return mid;
            }
            if(nums[mid] >= nums[st]) {
                if(nums[st] <= target && nums[mid] > target) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            } else {
                if(nums[end] >= target && nums[mid] < target) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};