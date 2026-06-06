class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int first = 0, second = -1;
        int row = matrix.size() - 1;
        int col = matrix[0].size() - 1;

        while(first <= row) {
            int mid = first + (row - first) / 2;
            if(target >= matrix[mid][0] && target <= matrix[mid][col]) {
                second = mid;
                break;
            } else if(target > matrix[mid][0] && target > matrix[mid][col]){
                first = mid + 1;
            } else {
                row = mid - 1;
            }
        }

        if(second == -1) return false;

        int left = 0;
        while(left <= col) {
            int mid = left + (col - left) / 2;
            if(matrix[second][mid] == target) {
                return true;
            } else if(target > matrix[second][mid]) {
                left = mid + 1;
            } else {
                col = mid - 1;
            }
        }

        return false;
    }
};