class Solution {
public:
    bool check(int n, int i) {
        if(i == n) return true;
        if(i > n) return false;
        if(i > n / 3) return false;
        return check(n, i * 3);
    }

    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        bool ans = check(n, 1);
        return ans;
    }
};