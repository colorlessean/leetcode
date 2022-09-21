class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();      // rows in the image on the side
        int n = matrix[0].size();   // columns in the image on the side
        
        int i = 0;
        int j = 0;
        
        // first find the row
        while (i < m) {
            if (matrix[i][0] == target) {
                return true;
            }
            if (i+1 != m && target >= matrix[i+1][0]) {
                i++;
            }
            else {
                break;
            }
        }
        
        // find the column or end up at the end of line
        while (j < n) {
            if(matrix[i][j] == target) {
                return true;
            }
            j++;
        }
        
        return false;
    }
};

