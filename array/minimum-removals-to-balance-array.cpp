class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int ans = n;
        int j = 0;

        for (int i = 0; i < n; i++) {
            while (nums[i] > 1LL * nums[j] * k) {
                j++;
            }
            ans = min(ans, n - (i - j + 1));
        }

        return ans;
    }
};