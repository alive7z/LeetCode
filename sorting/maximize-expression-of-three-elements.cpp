class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int m1 = INT_MIN, m2 = INT_MIN, m3 = INT_MAX;
        for(int val : nums) {
            if(val > m1) {
                m2 = m1; 
                m1 = val;
            } else if(val > m2) m2 = val;
            m3 = min(m3, val);
        }
        return m1 + m2 - m3;
    }
};