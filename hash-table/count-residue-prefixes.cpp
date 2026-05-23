class Solution {
public:
    int residuePrefixes(string s) {
        set<char> ans;
        int count = 0;
        for(int i = 0; i<s.length(); i++) {
            ans.insert(s[i]);
            if(ans.size() == (i+1) % 3) {
                count++;
            }
        }
        
        return count;
    }
};