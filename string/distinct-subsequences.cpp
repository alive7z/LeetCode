class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        
        vector<double> prev(n + 1, 0), curr(n + 1, 0);

        prev[0] = curr[0] = 1;

        for(int i = 1; i <= m; i++) {
            for(int j = n; j > 0; j--) {
                if(s[i-1] == t[j-1]) {
                    prev[j] = prev[j-1] + prev[j];
                } else {
                    prev[j] = prev[j];
                }
            }
        }

        return (int)prev[n];
    }
};