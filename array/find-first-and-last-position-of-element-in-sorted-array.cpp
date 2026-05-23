class Solution {
public:
    int firstOccurence(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1, ans = -1;
        while(st<=end) {
            int mid = st + (end-st)/2;
            if(nums[mid]==target) {
                ans = mid;
                end = mid - 1;
            } else if(target > nums[mid]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
    int lastOccurence(vector<int>& nums, int target) {
        int st = 0, end = nums.size() - 1, ans = -1;
        while(st<=end) {
            int mid = st + (end-st)/2;
            if(nums[mid]==target) {
                ans = mid;
                st = mid + 1;
            } else if(target > nums[mid]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int firstOccur = firstOccurence(nums, target);
        int lastOccur = lastOccurence(nums, target);
        ans.push_back(firstOccur);
        ans.push_back(lastOccur);
        return ans;
    }
};