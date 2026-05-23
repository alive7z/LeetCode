class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                int a = (i + nums[i]) % n;
                result.push_back(nums[a]);
            } 
            else if (nums[i] < 0) {
                int a = (i + nums[i]) % n;
                if (a < 0) a += n;
                result.push_back(nums[a]);
            } 
            else {
                result.push_back(nums[i]);
            }
        }

        return result;
    }
};