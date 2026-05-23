class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        vector<int> ans(2, -1);
        if(nums.size() < 2) return ans;
        unordered_map<int, int> m;
        for(int val : nums) {
            m[val]++;
        }
        vector<int> a;
        for(auto itr : m) {
            a.push_back(itr.first);
        }
        sort(a.begin(), a.end());
        int b = a[0], c = m[b];
        for(int i = 1; i<a.size(); i++) {
            if(m[a[i]] != c) {
                return {b, a[i]};
            }
        }
        return ans;
    }
};