class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for(int i = 1; i < s.length(); i++) {
            if((abs((int) s[i-1] - (int) s[i])) > 2) {
                return false;
            }
        }
        return true;
    }
};