class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int> front(m, 0);
        for(int i = 0; i < m; i++) {
            front[i] = triangle[m-1][i];
        }
        for(int i = m - 2; i >= 0; i--) {
            vector<int> curr(m, 0);
            for(int j = i; j >= 0; j--) {
                curr[j] = triangle[i][j] + min(front[j], front[j+1]);
            }
            front = curr;
        }
        return front[0];
    }
};