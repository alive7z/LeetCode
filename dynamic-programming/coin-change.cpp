class Solution {
public:
    void combinations(vector<int>& coins, int amount, int cnt, int i, int& ans) {
        if (cnt >= ans) return;
        if(i == coins.size()) {
            if(amount == 0) {
                ans = min(ans, cnt);
            }
            return;
        }
        if(coins[i] <= amount) {
            combinations(coins, amount - coins[i], cnt + 1, i, ans);
        }
        combinations(coins, amount, cnt, i + 1, ans);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size() == 0 && amount > 0) return -1;
        if(amount == 0) return 0;
        int cnt = 0, ans = INT_MAX;
        combinations(coins, amount, cnt, 0, ans);
        return ans == INT_MAX ? -1 : ans;
    }
};