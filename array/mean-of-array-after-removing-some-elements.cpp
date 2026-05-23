class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        double sum = 0;
        int k = n / 20;
        for(int i = k; i < n - k; i++) {
            sum += arr[i];
        }
        return sum / (n - 2 * k);
    }
};