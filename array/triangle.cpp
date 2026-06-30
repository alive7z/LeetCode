class Solution {
public:
    int minimumPath(vector<vector<int>>& triangle, int i, int j, int m, int n) {
        if(i == m - 1) return triangle[i][j];
        int mini = 0;
        int adjacent = triangle[i][j] + minimumPath(triangle, i + 1, j, m, n);
        int diagonal = triangle[i][j] + minimumPath(triangle, i + 1, j + 1, m, n);
        return mini = min(adjacent, diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[0].size();
        return minimumPath(triangle, 0, 0, m, n);
    }
};