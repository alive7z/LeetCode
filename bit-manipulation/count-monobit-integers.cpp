class Solution {
public:
    int countMonobit(int n) {
        int ans = 0, sum = 1;
        int count = 0;
        while(ans <= n) {
            count++;
            ans += sum;
            sum *= 2;
        }
        return count;
    }
};