class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        int length = 0;
        bool odd = false;
        for(char c: s) {
            mp[c]++;
        }
        for(auto it: mp) {
            length += (it.second / 2) * 2;
            if(it.second % 2 == 1) odd = true;
        }
        if(odd) length++;
        return length;
    }
};