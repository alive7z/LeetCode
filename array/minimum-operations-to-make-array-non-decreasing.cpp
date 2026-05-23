class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0, prev = nums[0], y = 0;
        for(int i = 1; i < n; i++) {
            long long x = nums[i] + y;
            if(x < prev) {
                long long z = prev - x;
                ans += z;
                y += z;
                x = prev;
            }
            prev = x;
        }
        return ans;
    }
};