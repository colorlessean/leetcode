// #define VERBOSE

class Solution {
public:    
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, int> mp, visited;
        
        vector<char> gene = {'A', 'G', 'T', 'C'};
        
        for (int i = 0; i < bank.size(); i++) {
            mp[bank[i]]++;
        }
        
        #ifdef VERBOSE
        for (auto iter = mp.begin(); iter != mp.end(); iter++) {
            cout << iter->first << " " << iter->second << endl;
        }
        #endif
        
        queue<string> q;
        q.push(start);
        
        int moves = 0;
        
        while(!q.empty()) {
            int size = q.size();
            for (int i=0; i < size; i++) {
                string curr = q.front();
                q.pop();
                
                if (curr == end) {
                    return moves;
                }
                
                for (int j = 0; j < 8; j++) {
                    string temp = curr;
                    for (int k = 0; k < 4; k++) {
                        temp[j] = gene[k];
                        #ifdef VERBOSE
                        cout << temp << endl;
                        #endif
                        if (mp[temp] && !visited[temp]) {
                            q.push(temp);
                            visited[temp]++;
                        }
                    }
                }
            }
            
            moves++;
            
        }
        
        return -1;
    }
};
