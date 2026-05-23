class Solution {
public:
    bool validDigit(int n, int x) {
        int num = n;
        bool check = false;
        while(num > 0) {
            int dig = num % 10;
            if(dig == x) check = true;
            if(num < 10 && dig == x) check = false; 
            num /= 10;
        }
        return check ? true : false;
    }
};