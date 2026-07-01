class Solution {
public:
    int minimumNumberOfCoins(vector<int>& coins, int amount, int i) {
        if(i == 0) {
            if(amount % coins[i] == 0) {
                return amount / coins[i];
            }
            return 1e9;
        }
        if(amount == 0) return 0;
        int notPick = minimumNumberOfCoins(coins, amount, i - 1);
        int pick = INT_MAX;
        if(amount >= coins[i]) {
            pick = minimumNumberOfCoins(coins, amount - coins[i], i);
        }
        return min(pick, notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = minimumNumberOfCoins(coins, amount, coins.size() - 1);
        if(ans >= 1e9) return -1;
        return ans;
    }
};