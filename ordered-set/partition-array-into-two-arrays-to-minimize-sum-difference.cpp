class Solution {
public:
    void partition(vector<int>& nums, int i, int cnt, int sum1, int sum2, int& ans) {
        if(i < 0) {
            if(cnt == nums.size() / 2) {
                ans = min(ans, abs(sum1 - sum2));
            }
            return;
        }
        if(cnt < nums.size() / 2) {
            partition(nums, i - 1, cnt + 1, sum1 + nums[i], sum2, ans);
        }
        partition(nums, i - 1, cnt, sum1, sum2 + nums[i], ans);
    }
    int minimumDifference(vector<int>& nums) {
        int ans = INT_MAX;
        int m = nums.size();
        partition(nums, m - 1, 0, 0, 0, ans);
        return ans;
    }
};