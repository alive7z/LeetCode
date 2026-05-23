class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_map<int, int> m;
        for(int i = 0; i < candyType.size(); i++) {
            m[candyType[i]]++;
        }
        int n = candyType.size() / 2;
        return m.size() > n ? n : m.size();
    }
};