class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size(), count = 0;
        long long sum = 0;
        for(int val : nums) {
            sum += val;
        }
        for(int i = 0; i<n-1; i++) {
            sum -= nums[i];
            int cnt = n - i - 1;
            if(nums[i] > double(sum) / cnt) {
                count++;
            }
        }
        return count;
    }
};