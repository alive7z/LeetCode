class Solution {
public:
    bool isHappy(int n) {
       if (n == 1 || n == 7) return true;
        while (true) {
            long long ans = 0;
            while (n > 0) {
                int digit = n % 10;
                ans += digit * digit;
                n /= 10;
            }
            n = ans;
            if (n == 1 || n == 7) return true;
            if (n < 10) return false;
        }
    }
};