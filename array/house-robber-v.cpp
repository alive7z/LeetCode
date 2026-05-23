class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        vector<int> ans = nums;
        int n = nums.size();
        long long x = 0, y = 0, z = 0;
        for(int i = 0; i<nums.size(); i++) {
            if(i > 0 && colors[i] != colors[i-1]) {
                x += max(y, z);
                y = 0; z = 0;
            }
            long long a = z + nums[i], b = max(y, z);
            y = a; z = b;
        }
        return x + max(y, z);
    }
};