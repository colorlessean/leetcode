#define VERBOSE

#define LEFT -1
#define RIGHT 1

class Solution {
private:
    // if you are a right turn and the turn right of you is a right turn proceed down and right
    // if you are a right turn and the turn right of you is a left then get stuck
        
    // if you are a left turn and the turn left of you is a left turn proceed down and left
    // if you are a left turn and the turn left of you is a right turn get stuck
        
    // once your row position is grid.size() then you are completed return the column value
        
    // any stuck condition means that you are done and return -1
    int solve(vector<vector<int>>& grid, int ball) {
        int row = 0; int col = ball;
        
        for (int i = 0; i < grid.size(); i++) {
            if (grid[row][col] == RIGHT) {
                // if we are stuck against a wall
                if (col == grid[0].size()-1) {
                    return -1;
                }
                // if we are stuck in a trough
                if (grid[row][col+1] == LEFT) {
                    return -1;
                }
                
                if (grid[row][col+1] == RIGHT) {
                    row++;
                    col++;
                }
            }
            else if (grid[row][col] == LEFT) {
                // if we are stuck against a wall
                if (col == 0) {
                    return -1;
                }
                // if we are stuck in a trough
                if (grid[row][col-1] == RIGHT) {
                    return -1;
                }
                
                if (grid[row][col-1] == LEFT) {
                    row++;
                    col--;
                }
            }
            else {
                // something is wrong
                return -1;
            }
        }
        return col;
    }
    
public:
    vector<int> findBall(vector<vector<int>>& grid) {        
        vector<int> ret;
        // there is a ball for each column
        for (int i = 0; i < grid[0].size(); i++) {
            ret.push_back(solve(grid, i));
        }
        return ret;
    }
};

