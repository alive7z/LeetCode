class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(int i = 0; i<nums.size(); i++) {
            mp[nums[i]] = i;
        }
        for(int val : nums) {
            int temp = val, cnt = 1;
            while(mp.find(temp - 1) != mp.end()) {
                cnt++;
                temp -= 1;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};