class Solution {
public:
    bool isAnagram(string s, string t) {
        int size1 = s.length();
        int size2 = t.length();
        if(size1 != size2) return false;
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for(int i = 0; i < size1; i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        if(mp1 == mp2) return true;
        else return false;
    }
};