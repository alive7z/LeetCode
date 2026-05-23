class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        vector<int> ans;
        int odd = 0, even = 0;
        for(int val : nums) {
            if(val % 2 == 0) even++;
            else odd++;
        }
        for(int val : nums) {
            if(val % 2 == 0) {
                ans.push_back(odd);
                even--;
            }
            else {
                ans.push_back(even);
                odd--;
            }
        }
        return ans;
    }
};