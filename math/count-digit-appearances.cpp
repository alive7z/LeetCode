class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count = 0;
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] == 0 && digit == 0) {
                count++; continue;
            }
            int x = nums[i];
            while(x != 0) {
                if(digit == x % 10) count++;
                x /= 10;
            }
        }
        return count;
    }
};