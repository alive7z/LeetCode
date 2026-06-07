class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        int num = n;
        if(num < 0) num = num * -1;
        while(num) {
            if(num % 2 == 1) {
                ans = ans * x;
                num = num - 1;
            } else {
                x = x * x;
                num /= 2;
            }
        }
        if(n < 0) return 1 / ans;
        return ans;
    }
};