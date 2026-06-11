class Solution {
public:
    void permutations(vector<int>& nums, vector<vector<int>>& ans) {
        int i = nums.size() - 1;
        while(i > 0 && nums[i] < nums[i-1]) i--;
        if(i == 0) {
            return;
        }
        for(int j = nums.size() - 1; j >= i; j--) {
            if(nums[j] > nums[i-1]) {
                swap(nums[j], nums[i-1]);
                break;
            }
        }
        reverse(nums.begin() + i, nums.end());
        ans.push_back(nums);
        permutations(nums, ans);
    }
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        ans.push_back(nums);
        permutations(nums, ans);
        return ans;
    }
};