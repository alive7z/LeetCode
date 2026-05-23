class Solution {
public:
    bool check(char a) {
        return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
    }
    string trimTrailingVowels(string s) {
        int n = s.size() - 1;
        for(int i = n; i >= 0; i--) {
            if(check(s[i])) continue;
            else return s.erase(i + 1);
        }
        return "";  
    }
};