class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        if(n == 0 && digits[n] == 9) {
            digits[n] = 0;
            digits.insert(digits.begin(), 1);
            return digits;
        }
        while(n >= 0) {
            if(digits[n] == 9) {
                digits[n] = 0;
                n--;
            } else {
                digits[n]++;
                return digits;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};