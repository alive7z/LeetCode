class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int i = 0, count = k;
        while(i < nums.size()) {
            if(nums[i] == 0) {
                count++;
            } else if(nums[i] == 1) {
                if(count < k) {
                    return false;
                } count = 0;
            }
            i++;
        }
        return true;
    }
};