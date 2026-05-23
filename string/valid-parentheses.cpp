class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for(char val : str) {
            if(val == '(' || val == '[' || val == '{') {
                s.push(val);
            } else {
                if(s.empty()) {
                    return false;
                }
                if((val == ')' && s.top() == '(') || (val == ']' && s.top() == '[') || (val == '}' && s.top() == '{')) {
                    s.pop();
                } else {
                    return false;
                }
            }
        }
        return s.size() == 0;
    }
};