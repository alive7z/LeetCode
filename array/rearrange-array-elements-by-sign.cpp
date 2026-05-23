class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> first, second, ans;
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] > 0) {
                first.push_back(nums[i]);
            } else {
                second.push_back(nums[i]);
            }
        }
        int i = 0;
        while(i < first.size() && i < second.size()) {
            ans.push_back(first[i]);
            ans.push_back(second[i]);
            i++;
        }
        return ans;
    }
};