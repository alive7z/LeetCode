class Solution {
public:
    int minCost(int n) {
        int ans = n;
        return ans * (ans - 1) / 2;
    }
};