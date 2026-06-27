class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int m, int n, int color) {
        if(sr < 0 || sr >= m || sc < 0 || sc >= n || image[sr][sc] == 0 || image[sr][sc] == color) return;
        image[sr][sc] = color;
        dfs(image, sr - 1, sc, m, n, color);
        dfs(image, sr + 1, sc, m, n, color);
        dfs(image, sr, sc - 1, m, n, color);
        dfs(image, sr, sc + 1, m, n, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        dfs(image, sr, sc, m, n, color);
        return image;
    }
};