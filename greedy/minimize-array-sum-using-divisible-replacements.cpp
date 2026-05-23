class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        long long sum = 0;
        
        unordered_set<int> us(nums.begin(), nums.end());

        for(int a : nums) {
            int val = a;
            for(int i = 1; i * i <= a; i++) {
                if(a % i == 0) {
                    if(us.find(i) != us.end()) {
                        val = min(val, i);
                    }
                    if(us.find(a / i) != us.end()) {
                        val = min(val, a / i);
                    }
                }
            }
            sum += val;
        }
        
        return sum;
    }
};