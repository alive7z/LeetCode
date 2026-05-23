class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> ans;
        for(int val : nums) {
            ans.push_back(val);
            while(ans.size() >= 2 && ans.back() == ans[ans.size() - 2]) {
                long long sum = ans.back() * 2;
                ans.pop_back();
                ans.pop_back();
                ans.push_back(sum);
            }
        }
        return ans;
    }
};