class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int ans = INT_MAX;
        bool check = false;
        for(int val : nums1) {
            if(val % 2 != 0) {
                check = true;
                ans = min(val, ans);
            }
        }
        if(check == false) return true;
        for(int val : nums1) {
            if(val % 2 == 0 && val < ans) {
                return false;
            }
        }
        return true;;
    }
};