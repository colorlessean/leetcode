#define VERBOSE

class Solution {
public:
    void recursion(string& tiles, vector<bool>& visited, unordered_set<string>& result, string& path) {
        // iterate over each letter in the tiles
        for (int i = 0; i < tiles.size(); i++) {
            
            // if we have not used aka "visited" the current letter
            if (!visited[i]) {
                // use the letter aka "visit"
                visited[i] = true;
                
                // construct the attempted word aka "path"
                path.push_back(tiles[i]); 
                
                // go into the recursion to try the next letter 
                recursion(tiles, visited, result, path);
                
                // if we return out we have completed that word aka "path"
                path.pop_back();
                
                // return the letter to the bank in other words backtrack on the path
                visited[i] = false;
            }
            
        }
        
        // when all letters have been used and thus path is exhausted add the word to the result set
        
        
        result.insert(path);
    }
    
    int numTilePossibilities(string tiles) {
        // back-tracking algorithm with an unordered_set
        // path will be each d
        
        unordered_set<string> result;
        string path = "";
        vector<bool> visited(tiles.size(), false);
        
        recursion(tiles, visited, result, path);
        
        return result.size() - 1;
    }
};
