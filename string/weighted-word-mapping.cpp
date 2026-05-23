class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(string word : words) {
            int sum = 0;
            for(char val : word) {
                sum += weights[val - 'a'];
            }
            int a = sum % 26;
            char c = 'z' - a;
            ans += c;
        }
        return ans; 
    }
};