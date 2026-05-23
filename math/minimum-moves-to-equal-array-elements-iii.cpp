class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        sort(nums.begin(), nums.end());
        int ans = nums[n-1] * n;
        for(int i = 0; i<n; i++) {
            sum += nums[i];
        }
        return ans - sum;
    }
};