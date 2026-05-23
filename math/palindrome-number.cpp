class Solution {
public:
    bool isPalindrome(int x) {
        long long rev = 0;
        int num = x;
        if(x < 0) return false;
        while(num != 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev == x;
    }
};