class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for(int val : st) {
            if(st.find(val - 1) == st.end()) {
                int temp = val;
                int cnt = 1;
                while(st.find(temp + 1) != st.end()) {
                    cnt++;
                    temp += 1;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};