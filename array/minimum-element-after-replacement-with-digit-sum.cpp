class Solution {
public:
    int minElement(vector<int>& nums) {
        int minimum = INT_MAX;
        for(int val : nums) {
            int sum = 0;
            while(val != 0) {
                sum += val % 10;
                val /= 10;
            }
            minimum = min(minimum, sum);
        }
        return minimum;
    }
};