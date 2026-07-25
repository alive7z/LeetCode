class Solution {
public:
    int maxProduct(int n) {
        int num = n;
        int first = INT_MIN, second = INT_MIN;
        first = num % 10;
        num /= 10;
        while(num != 0) {
            int dig = num % 10;
            if(dig > first) {
                second = first;
                first = dig;
            } else if(dig > second) {
                second = dig;
            }
            num /= 10;
        }
        if(second == INT_MIN) return first;
        return first * second;
    }
};