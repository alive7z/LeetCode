class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> check(256, false);
        int ans = 0, cnt = 0;
        int i = 0, j = 0;
        while(j < s.length()) {
            if(check[s[j] - 'a'] == true) {
                ans = max(ans, cnt);
                while(s[i] != s[j]) {
                    check[s[i++] - 'a'] = false;
                }
                check[s[i++] - 'a'] = false;
                cnt = j - i + 1;
                check[s[j++] - 'a'] = true;
            } else {
                check[s[j++] - 'a'] = true;
                cnt++;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};