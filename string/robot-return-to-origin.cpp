class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for(char val : moves) {
            if(val == 'U') {
                y++;
            } else if(val == 'D') {
                y--;
            } else if(val == 'L') {
                x--;
            } else {
                x++;
            }
        }
        return (x == 0 && y == 0);
    }
};