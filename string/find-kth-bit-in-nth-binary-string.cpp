class Solution {
public:
    char findKthBit(int n, int k) {
        string val = "0";
        int i = 1;
        for(int i = 2; i <= n; i++) {
            string temp = val;
            for(char &c : temp) {
                c = (c == '0') ? '1' : '0';
            }
            reverse(temp.begin(), temp.end());
            val = val + "1" + temp;
        }
        return val[k - 1];
    }
};