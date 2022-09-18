// #define VERBOSE

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // trival solution
        if (n == 0) return tasks.size();
        
        unordered_map<char, int> occurances;
        int maximum = 0;
        int maximum_count = 0;
        
        for (int i = 0; i < tasks.size(); i++) {
            occurances[tasks[i]]++;
            if (occurances[tasks[i]] == maximum) {
                maximum_count++;
            }
            else if (occurances[tasks[i]] > maximum) {
                maximum = max(maximum, occurances[tasks[i]]);
                maximum_count = 1;
            }
        }
        
        #ifdef VERBOSE
        for (auto iter = occurances.begin(); iter != occurances.end(); iter++) {
            cout << iter->first << " " << iter->second << endl;
        }
        #endif
        
        int num = (maximum-1)*(n+1) + 1;
        num += maximum_count - 1;
        
        return max(num, (int)tasks.size());
    }
};

