class Solution {
public:
    string reverseByType(string s) {
        int i = 0, j = s.length() - 1;
        while(i < j) {
            if(s[i] < 'a' || s[i] > 'z') {
                i++;
            } else if(s[j] < 'a' || s[j] > 'z'){
                j--;
            } else {
                swap(s[i], s[j]);
                i++; j--;
            }
        }
        int a = 0, b = s.length() - 1;
        while(a < b) {
            if(s[a] >= 'a' && s[a] <= 'z') {
                a++;
            } else if(s[b] >= 'a' && s[b] <= 'z'){
                b--;
            } else {
                swap(s[a], s[b]);
                a++; b--;
            }
        }
        return s;
    }
};