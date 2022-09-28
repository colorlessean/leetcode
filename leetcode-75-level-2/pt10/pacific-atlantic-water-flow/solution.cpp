class Solution {
public:
    int m, n;
    
    // the individual accessable from ocean
    vector<vector<bool>> atlantic, pacific;
    vector<vector<int>> ans;
    
    // use DFS to get to the edges
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c) {
        if (visited[r][c]) {
            return;
        }
        
        visited[r][c] = true;
        
        if (atlantic[r][c] && pacific[r][c]) {
            ans.push_back(vector<int>{r, c});
        }
        
        // now do the dfs from the current cell if height of the next cell is greater
        if (r+1 < m && heights[r+1][c] >= heights[r][c]) {
            dfs(heights, visited, r+1, c);
        }
        if (r-1 >= 0 && heights[r-1][c] >= heights[r][c]) {
            dfs(heights, visited, r-1, c);
        }
        if (c+1 < n && heights[r][c+1] >= heights[r][c]) {
            dfs(heights, visited, r, c+1);
        }
        if (c-1 >= 0 && heights[r][c-1] >= heights[r][c]) {
            dfs(heights, visited, r, c-1);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (!heights.size()) {
            return ans;
        }
        
        m = heights.size();
        n = heights[0].size();
        
        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n-1);
        }
        for (int i = 0; i < n; i++) {
            dfs(heights, pacific, 0, i);
            dfs(heights, atlantic, m-1, i);
        }
        
        return ans;
    }
};

