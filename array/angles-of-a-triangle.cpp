class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        vector<double> ans;
        int a = sides[0], b = sides[1], c = sides[2];
        
        if((a + b) <= c || (a + c) <= b || (b + c) <= a) return ans;

        double x = acos(((b * b) + (c * c) - (a * a)) / (2.0 * b * c));
        double y = acos(((a * a) + (c * c) - (b * b)) / (2.0 * a * c));
        double z = acos(((a * a) + (b * b) - (c * c)) / (2.0 * a * b));

        x = x * 180.0 / M_PI;
        y = y * 180.0 / M_PI;
        z = z * 180.0 / M_PI;

        ans.push_back(x);
        ans.push_back(y);
        ans.push_back(z);

        sort(ans.begin(), ans.end());
        return ans;
    }
};