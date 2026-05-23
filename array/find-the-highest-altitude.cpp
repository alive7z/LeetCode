class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int num = 0;
        int maximum = 0;
        for(int i = 0; i<gain.size(); i++) {
            num += gain[i];
            maximum = max(maximum, num);
        }
        return maximum;
    }
};