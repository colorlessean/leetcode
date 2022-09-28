#define VERBOSE

#define EMPTY 0
#define FRESH 1
#define ROTTEN 2

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // the directions for each iteration
        vector<int> i_dir = {-1, 0, 1, 0};
        vector<int> j_dir = {0, -1, 0, 1};
        
        // we use a queue to keep track of the next rotten ones
        queue<pair<int, int>> q;
        
        int m = grid.size();
        int n = grid[0].size();
        
        // keep track of how many fresh are left
        // if we finish BFS and there are still oranges then we know to return -1
        int num_of_fresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == FRESH) {
                    num_of_fresh++;
                }
                else if (grid[i][j] == ROTTEN) {
                    q.push({i, j});
                }
            }
        }
        
        int ans = -1;
        
        // so until we have expended all the rotten oranges
        while(!q.empty()) {
            int remain = q.size();
            while (remain--) {
                pair<int, int> orange = q.front();
                q.pop();
                
                // check each direction
                for (int a = 0; a < 4; a++) {
                    int i = orange.first + i_dir[a];
                    int j = orange.second + j_dir[a];
                    
                    // this is a valid direction to rot an orange at
                    if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == FRESH) {
                        grid[i][j] = ROTTEN;
                        q.push({i, j});
                        num_of_fresh--;
                    }
                }
            }
            ans++;
        }
        
        if (num_of_fresh > 0) {
            return -1;
        }
        
        if (ans == -1) {
            return 0;
        }
        
        return ans;
    }
};

