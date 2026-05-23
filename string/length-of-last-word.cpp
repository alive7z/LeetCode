class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.size() - 1, len = 0;
        while(end >= 0 && s[end] == ' ') {
            end--;
        }
        for(int i = end; i >= 0; i--) {
            if(s[i] != ' ') {
                len++;
            } else break;
        }
        return len;
    }
};