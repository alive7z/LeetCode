class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<int> prev(n + 1, false), curr(n + 1, false);
        prev[0] = true;

        for(int i = 1; i <= m; i++) {
            curr[0] = false;
        }

        for(int j = 1; j <= n; j++) {
            if(p[j-1] == '*') prev[j] = prev[j-1];
            else prev[j] = false;
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i-1] == p[j-1] || p[j-1] == '?') {
                    curr[j] = prev[j-1];
                } else if(p[j-1] == '*') {
                    curr[j] = prev[j] || curr[j-1];
                } else {
                    curr[j] = false;
                }
            }
            prev = curr;
        }

        return prev[n];
    }
};