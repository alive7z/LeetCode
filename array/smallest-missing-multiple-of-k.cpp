class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> store(100, 0);
        int n = 0;
        for(int val : nums) {
            if(val % k == 0) {
                store[val-1]++;
            }
        }
        for(int i = 0; i < store.size(); i++) {
            if(store[i] == 0 && (i + 1) % k == 0) return i + 1;
        }
        while(n < 100) {
            n += k;
        }
        return n;
    }
};