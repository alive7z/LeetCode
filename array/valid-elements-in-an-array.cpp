class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums;

        vector<int> ans;
        vector<bool> check(n, false);
        check[0] = true;
        check[n-1] = true;

        int left = nums[0];
        for(int i = 1; i<n; i++) {
            if(nums[i] > left) {
                check[i] = true;
            }
            left = max(left, nums[i]);
        }

        int right = nums[n-1];
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] > right) {
                check[i] = true;
            }
            right = max(right, nums[i]);
        }

        for(int i = 0; i<n; i++) {
            if(check[i]) {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};