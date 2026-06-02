class Solution {
public:
    vector<int> generateRow(int row) {
        long long ans = 1;
        vector<int> temp;
        temp.push_back(1);
        for(int col = 1; col < row; col ++) {
            ans = ans * (row - col);
            ans /= col;
            temp.push_back(ans);
        }
        return temp;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int row = 1; row <= numRows; row++) {
            vector<int> temp = generateRow(row);
            ans.push_back(temp);
        }
        return ans;
    }
};