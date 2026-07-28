class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();

        string half = s.substr(0, n / 2);
        sort(half.begin(), half.end());

        for (int i = 0; i < n / 2; i++) {
            s[i] = half[i];
            s[n - 1 - i] = half[i];
        }

        return s;
    }
};