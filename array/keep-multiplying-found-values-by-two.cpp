class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> m(nums.begin(), nums.end());
        int ans = original;
        while(m.find(ans) != m.end()) {
            ans *= 2;
        }
        return ans;
    }
};