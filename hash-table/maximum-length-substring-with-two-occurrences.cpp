class Solution {
public:
    int maximumLengthSubstring(string s) {
        int size = 0;
        vector<int> alphabets(26, 0);
        int i = 0, j = 0;
        while(j < s.size()) {
            if(alphabets[s[j] - 'a'] < 2) {
                alphabets[s[j] - 'a']++;
                j++;
            } else {
                size = max(size, j - i);
                alphabets[s[i] - 'a']--;
                i++;
            }
        }
        size = max(size, j - i);
        return size;
    }
};