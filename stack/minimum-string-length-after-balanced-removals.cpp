class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int a = 0, b = 0;
        for(int i = 0; i<s.length(); i++) {
            if(s[i] == 'a') {
                a++;
            } else b++;
        }
        if(a==b) {
            return 0;
        } else {
            if(a > b) return a - b;
            if(a < b) return b - a;
        }
        return 0;
    }
};