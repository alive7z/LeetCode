class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyDay = prices[0], maximum = 0;
        for(int i = 1; i<prices.size(); i++) {
            if(buyDay < prices[i]) {
                maximum = max(maximum, prices[i] - buyDay);
            } else {
                buyDay = prices[i];
            }
        }
        return maximum;
    }
};