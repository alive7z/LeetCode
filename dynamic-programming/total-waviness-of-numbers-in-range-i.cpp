class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int a = num1, b = num2;
        int waves = 0;
        for(int i = a; i <= b; i++) {
            string str = to_string(i);
            int size = str.size() - 1;
            for(int j = 1; j < size; j++) {
                int start = str[j-1] - '0';
                int mid = str[j] - '0';
                int end = str[j+1] - '0';
                if((mid > start && mid > end) || (mid < start && mid < end)) waves++;
            }
        }
        return waves;
    }
};