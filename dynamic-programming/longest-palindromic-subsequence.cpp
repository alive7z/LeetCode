class Solution {
public:
    int palindrome(string s, int i, int j) {
        if(i > j) {
            return 0;
        }
        if(i == j) return 1;
        if(s[i] == s[j]) {
            return 2 + palindrome(s, i + 1, j - 1);
        }
        return max(palindrome(s, i + 1, j), palindrome(s, i, j - 1));
    }
    int longestPalindromeSubseq(string s) {
        return palindrome(s, 0, s.size() - 1);
    }
};