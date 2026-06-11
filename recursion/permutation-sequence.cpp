class Solution {
public:
    string getPermutation(int n, int k) {
        if(n == 1) return "1";

        vector<int> nums;

        int fact = 1;
        for(int i = 1; i <= n; i++) {
            fact *= i;
        }

        k--;

        int div = fact / n;
        int mod = k % div;
        int pos = k / div;

        nums.push_back(pos + 1);
        for(int i = 1; i <= n; i++) {
            if(i != pos + 1) {
                nums.push_back(i);
            }
        }

        for(int k = 0; k < mod; k++) {
            int i = nums.size() - 1;
            while(i > 0 && nums[i] <= nums[i-1]) i--;
            for(int j = nums.size() - 1; j >= i; j--) {
                if(nums[j] > nums[i-1]) {
                    swap(nums[j], nums[i-1]);
                    break;
                }
            }
            reverse(nums.begin() + i, nums.end());
        }

        string str = "";
        
        for(int val : nums) {
            str += to_string(val);
        }

        return str;
    }
};