class Solution {
public:
    int maximum69Number (int num) {
        int n = num;
        int pos = -1;
        vector<int> ans;
        
        while(n > 0) {
            int dig = n % 10;
            ans.push_back(dig);
            n /= 10;
        }
        for(int i = 0; i<ans.size(); i++) {
            if(ans[i] == 6) {
                pos = i;
            }
        }

        if(pos == -1) return num;

        int add = 1;
        for(int i = 0; i < pos; i++) add *= 10;

        return num + 3 * add;
    }
};