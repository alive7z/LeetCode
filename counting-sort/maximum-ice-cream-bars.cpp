class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int cnt = 0;
        int temp = coins;
        int num = *max_element(costs.begin(), costs.end());
        vector<int> store(num + 1, 0);
        for(int val : costs) {
            store[val]++;
        }
        for(int i = 1; i < store.size(); i++) {
            while(store[i]) {
                if(i <= temp) {
                    cnt++;
                    temp -= i;
                    store[i]--;
                } else break;
            }
        }
        return cnt;
    }
};