class Solution {
public:
    bool check(vector<int>& nums) {
        int drop = 0;
        for(int i = 1; i<nums.size(); i++) {
            if(nums[i] < nums[i-1]) {
                drop++;
            }
        }
        if(nums.back() > nums.front()) drop++;
        return drop <= 1;
    }
};