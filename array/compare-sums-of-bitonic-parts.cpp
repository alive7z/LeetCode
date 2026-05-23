class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        bool check = false;
        long long int left = 0, right = 0;
        for(int i = 1; i<nums.size(); i++) {
            if(nums[i] > nums[i-1]) {
                left += nums[i - 1];
            } else {
                if(!check) {
                    left += nums[i-1];
                    right += nums[i - 1];
                    check = true;
                }
                right += nums[i];
            }
        }
        if(left == right) return -1;
        return left > right ? 0 : 1;
    }
};