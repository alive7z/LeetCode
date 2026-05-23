class Solution {
public:
    int mirrorFrequency(string s) {
        int ans = 0;
        
        vector<bool> check(128, false);
        vector<int> freq(128, 0);
        
        for(char val : s) freq[val]++;
        
        for(char val : s) {
            if(check[val]) continue;
            char a = isdigit(val) ? char('0' + '9' - val) : char('a' + 'z' - val);
            ans += abs(freq[val] - freq[a]);
            check[val] = true;
            check[a] = true;
        }
        
        return ans;
    }
};