class Solution {
public:
    void combinations(vector<int>& coins, int amount, int i, int& ans, int count) {
        if(i == coins.size()) {
            if(amount == 0) {
                ans = min(ans, count);
            }
            return;
        }
        if(amount >= coins[i]) {
            combinations(coins, amount - coins[i], i, ans, count + 1);
        } 
        combinations(coins, amount, i + 1, ans, count);
    }
    int coinChange(vector<int>& coins, int amount) {
        int count = 0, i = 0, ans = INT_MAX;
        combinations(coins, amount, i, ans, count);
        return ans == INT_MAX ? -1 : ans;
    }
};