class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> check(256, false);
        int ans = 0, cnt = 0;
        int i = 0, j = 0;
        while(j < s.length()) {
            if(check[s[j]] == true) {
                ans = max(ans, cnt);
                while(s[i] != s[j]) {
                    check[s[i++]] = false;
                }
                check[s[i++]] = false;
                cnt = j - i + 1;
                check[s[j++]] = true;
            } else {
                check[s[j++]] = true;
                cnt++;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};