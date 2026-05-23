class Solution {
public:
    string removeOuterParentheses(string s) {
        string str;
        int open = 0;
        for(char c: s) {
            if(c == '(' && open++ > 0) str += c;
            if(c == ')' && open-- > 1) str += c;
        }
        return str;
    }
};