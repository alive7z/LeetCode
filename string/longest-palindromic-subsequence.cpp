class Solution {
public:
    int length(string s, int i, int j) {
        if(i > j) return 0;
        if(i == j) return s[i] == s[j];
        if(s[i] == s[j]) {
            return 2 + length(s, i + 1, j - 1);
        }
        return max(length(s, i + 1, j), length(s, i, j - 1));
    }
    int longestPalindromeSubseq(string s) {
        return length(s, 0, s.size() - 1);
    }
};