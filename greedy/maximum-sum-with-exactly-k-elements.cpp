class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maximum = *max_element(nums.begin(), nums.end()), sum = 0;
        for(int i = 0; i<k; i++) {
            sum += maximum + i;
        }
        return sum;
    }
};