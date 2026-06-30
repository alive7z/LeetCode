class Solution {
public:
    int uniquePaths(int m, int n) {
        int a = m + n - 2;
        int b = min(m - 1, n - 1);
        long long res = 1;
        for(int i = 1; i <= b; i++) {
            res = res * (a - b + i) / i;
        }
        return (int)res;
    }
};