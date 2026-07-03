class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if(n == 0) return 0;

        vector<unsigned long long int> prev(amount + 1, 0);
        
        for(int a = 0; a <= amount; a++) {
            if(a % coins[0] == 0) {
                prev[a] = 1;
            }
        }

        for(int i = 1; i < n; i++) {
            vector<unsigned long long int> curr(amount + 1, 0);
            for(int j = 0; j <= amount; j++) {
                unsigned long long int notPick = prev[j];
                unsigned long long int pick = 0;
                if(coins[i] <= j) {
                    pick = curr[j - coins[i]];
                }
                curr[j] = pick + notPick;
            }
            prev = curr;
        }

        return prev[amount];
    }
};