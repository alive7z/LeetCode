class Solution {
public:
    
    bool check(int n) {
        if(n <= 1) {
            return false;
        }
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) return false; 
        }
        return true;
    }
    
    int ans(int i, int j) {
        int sum = 0;
        while(i <= j) {
            if(check(i)) {
                sum += i;
            }
            i++;
        }
        return sum;
    }
    
    int sumOfPrimesInRange(int n) {
        int num = n, rev = 0;
        while(num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return ans(min(n, rev), max(n, rev));
    }
};