class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0, n = num;
        while(n != 0) {
            if(n % 2 == 0) {
                n /= 2;
            } else {
                n = n - 1;
            }
            count++;
        }
        return count;
    }
};