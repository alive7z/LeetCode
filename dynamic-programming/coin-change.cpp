class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);
        for(int j = 0; j <= amount; j++) {
            if(j % coins[0] == 0) {
                prev[j] = j / coins[0];
            } else {
                prev[j] = 1e9;
            }
        }
        for(int i = 1; i < n; i++) {
            vector<int> curr(amount + 1, 0);
            for(int j = 0; j <= amount; j++) {
                int pick = INT_MAX;
                if(j >= coins[i]) {
                    pick = 1 + curr[j-coins[i]];
                }
                int notPick = 0 + prev[j];
                curr[j] = min(pick, notPick);
            }
            prev = curr;
        }
        if(prev[amount] >= 1e9) return -1;
        return prev[amount];
    }
};