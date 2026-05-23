class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans = 0, sum = 0;
        int num = n, mult = 1;
        while(num > 0) {
            int dig = num % 10;
            if(dig != 0) {
                sum += dig;
                ans += dig * mult;
                mult *= 10;
            }
            num /= 10;
        }
        return ans * sum;
    }
};