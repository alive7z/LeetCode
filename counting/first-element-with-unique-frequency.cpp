class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> freq1;
        unordered_map<int, int> freq2;
        int ans = 0;
        for(int val : nums) {
            freq1[val]++;
        }
        for(auto itr : freq1) {
            freq2[itr.second]++;
        }
        for(int val : nums) {
            if(freq2[freq1[val]] == 1) {
                return val;
            }
        }
        return -1;
    }
};