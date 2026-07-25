class Solution {
public:
    int maxProduct(int n) {
        int num = n, maxi = 0;
        int first = num % 10;
        num /= 10;
        while(num != 0) {
            int mul = (num % 10) * first;
            first = num % 10;
            maxi = max(maxi, mul);
            num /= 10;
        }
        return maxi;
    }
};