class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> mp;
        int ans = INT_MIN;
        int cnt = 0, val;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }
        for(auto itr : mp) {
            if(cnt == 0) {
                val = itr.first;
                cnt = 1;
            } else {
                if(itr.first == val + 1) {
                    cnt++;
                    val = itr.first;
                } else {
                    ans = max(ans, cnt);
                    cnt = 1;
                    val = itr.first;
                }
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};