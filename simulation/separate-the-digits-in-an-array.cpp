class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int val : nums) {
            string temp = to_string(val);
            for(char c : temp) {
                ans.push_back(c - '0');
            }
        }
        return ans;
    }
};