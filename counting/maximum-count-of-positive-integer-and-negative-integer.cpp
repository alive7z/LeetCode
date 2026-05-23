class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

        int left = 0, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > 0) {
                right = mid;
            }
            else {
                left = mid + 1;
            };
        }
        int firstPos = left;

        left = 0, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= 0) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        int firstNonNeg = left;

        int negatives = firstNonNeg;
        int positives = n - firstPos;

        return max(negatives, positives);
    }
};