class Solution {
public:
    int minimumFlips(int n) {
        string ans = "";
        int num = n, flip = 0;
        while(num > 0) {
            ans += (num % 2) * '0';
            num /= 2;
        }
        reverse(ans.begin(), ans.end());
        string rev = ans;
        reverse(rev.begin(), rev.end());
        for(int i = 0; i<ans.size(); i++) {
            if(ans[i] != rev[i]) flip++;
        }
        return flip;
    }
};