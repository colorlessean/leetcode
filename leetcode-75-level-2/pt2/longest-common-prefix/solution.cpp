class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int shortest = INT_MAX;
        for (int i = 0; i < strs.size(); i++) {
            if (strs[i].size() < shortest) {
                shortest = strs[i].size();
            }
        }
        
        string prefix = "";
        for (int i = 0; i < shortest; i++) {
            char next = strs[0][i];
            bool all_have_it = true;
            
            for (int j = 0; j < strs.size(); j++) {
                if (strs[j][i] != next) {
                    all_have_it = false;
                    break;
                }
            }
            
            if (!all_have_it) {
                break;
            }
            
            prefix.push_back(next);
        }
        
        return prefix;
    }
};

