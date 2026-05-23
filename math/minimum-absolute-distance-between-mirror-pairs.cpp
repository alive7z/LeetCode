class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int ans = INT_MAX;
        unordered_map<int, int> mp;
        for(int i = 0; i<nums.size(); i++) {
            if(mp.find(nums[i]) != mp.end()) {
                ans = min(ans, i - mp[nums[i]]);
            }
            int num = nums[i];
            int rev = 0;
            while(num % 10 == 0 && num != 0) {
                num /= 10;
            }
            while (num > 0) {
                rev = rev * 10 + num % 10;
                num /= 10;
            }
            mp[rev] = i;
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};