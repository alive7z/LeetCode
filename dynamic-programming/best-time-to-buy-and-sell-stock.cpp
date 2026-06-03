class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestBuy = prices[0], totalProfit = 0;
        for(int i = 1; i<prices.size(); i++) {
            if(bestBuy > prices[i]) {
                bestBuy = prices[i];
                totalProfit = 0;
                continue;
            }
            totalProfit = max(totalProfit, prices[i] - bestBuy);
        }
        return totalProfit;
    }
};