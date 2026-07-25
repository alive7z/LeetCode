class Solution {
public:
    int maxProduct(int n) {
        vector<int> vec;
        int num = n;
        while(num != 0) {
            vec.push_back(num % 10);
            num /= 10;
        }
        sort(vec.begin(), vec.end());
        int size = vec.size();
        if(size == 1) return vec[size-1];
        return vec[size-1] * vec[size-2];
    }
};