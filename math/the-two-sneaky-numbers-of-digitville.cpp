class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        vector<bool> seen(n, false);
        for(int i = 0; i < n; i++) {
            if(seen[nums[i]]) {
                ans.push_back(nums[i]);
            } else {
                seen[nums[i]] = true;
            }
        }
        return ans;
    }
};