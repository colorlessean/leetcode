// #define VERBOSE

class Solution {
private:
    // my directional helper functions
    // each will return the value at the location and then move the referenced index value by 1 unit in the direction specified
    int travel_left(vector<vector<int>>& matrix, int column, int& row) {
        return matrix[column][row--];
    }
    
    int travel_right(vector<vector<int>>& matrix, int column, int& row) {
        return matrix[column][row++];
    }
    
    int travel_up(vector<vector<int>>& matrix, int &column, int row) {
        return matrix[column--][row];
    }
    
    int travel_down(vector<vector<int>>& matrix, int &column, int row) {
        return matrix[column++][row];
    }
    
    // direction should be an enum of 0, 1, 2, 3 for right, down, left, up
    int switch_direction(int direction) {
        return (direction + 1) % 4;
    }

public:
    // matrix[col][row] 
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // what we are going to return
        vector<int> ret;
        if (matrix[0].size() == 0) {
            return ret;
        }
        
        // 0 right, 1 down, 2 left, 3 up and repeat
        int direction = 0;
        if (matrix[0].size() == 1) {
            direction = 1;
        }
        
        // fences for our column and row traversals
        int col_start = 0, col_end = matrix.size(), row_start = -1, row_end = matrix[0].size();
        
        #ifdef VERBOSE
        cout << row_start << " " << row_end << " " << col_start << " " << col_end << endl;
        #endif
        
        // actual index values we will use
        int row = 0, col = 0;
        
        // when we converge on the last value in the spiral we can exit the loop
        for (int i = 0; i < matrix.size() * matrix[0].size(); i++) {
            int val = 0;
            
            // bear in mind we cannot pass the break onto the loop but we can a continue statement
            switch (direction) {
                case 0:
                    #ifdef VERBOSE
                    cout << "right ";
                    #endif
                    val = travel_right(matrix, col, row);
                    if (row >= row_end - 1) {
                        direction = switch_direction(direction);
                        row_end--;
                    }
                    break;
                case 1:
                    #ifdef VERBOSE
                    cout << "down  ";
                    #endif
                    val = travel_down(matrix, col, row);
                    if (col >= col_end - 1) {
                        direction = switch_direction(direction);
                        col_end--;
                    }
                    break;
                case 2:
                    #ifdef VERBOSE
                    cout << "left  ";
                    #endif
                    val = travel_left(matrix, col, row);
                    if (row <= row_start + 1) {
                        direction = switch_direction(direction);
                        row_start++;
                    }
                    break;
                case 3:
                    #ifdef VERBOSE
                    cout << "up    ";
                    #endif
                    val = travel_up(matrix, col, row);
                    if (col <= col_start + 1) {
                        direction = switch_direction(direction);
                        col_start++;
                    }
                    break;
                default:
                    break;
            }
            
            #ifdef VERBOSE
            cout << " | " << row << " " << row_start << " " << row_end << " | " << col << " " << col_start << " " << col_end << " | ";
            #endif
            
            #ifdef VERBOSE
            cout << val << endl;
            #endif
            
            ret.push_back(val);
        }
            
        return ret;
    }
};

