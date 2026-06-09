class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp(nums.begin(), nums.end());
        int ans = 0;
        for(int val : nums) {
            if(mp.find(val - 1) == mp.end()) {
                int temp = val;
                int cnt = 1;
                while(mp.find(temp + 1) != mp.end()) {
                    cnt++;
                    temp += 1;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};