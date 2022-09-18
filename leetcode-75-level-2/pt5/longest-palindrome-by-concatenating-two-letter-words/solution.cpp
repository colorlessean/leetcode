// Need either a pair of forward and backwards letters
// or a double letter instance to make a palindrome
// #define VERBOSE

class Solution {
public:
    unordered_map<string, int> occurances;
    
    int longestPalindrome(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            occurances[words[i]]++;
        }
        
        #ifdef VERBOSE
        for (auto iter = occurances.begin(); iter != occurances.end(); iter++) {
            cout << iter->first << " " << iter->second << endl;
        }
        #endif
        
        int size = 0;
        
        // check all the already palindromes
        bool addedOdd = false;
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];

            if (word[0] == word[1]) {
                // any even number already palindrome words can have their occurances added
                // so we get a palindrome word and there are even occurances
                if (occurances[word] % 2 == 0) {
                    size += (occurances[word] * 2);
                    occurances[word] = 0;
                }
                // we can only add a single odd occurances one to the middle
                else if (!addedOdd) {
                    size += (occurances[word] * 2);
                    addedOdd = true;
                    occurances[word] = 0;
                }
                else {
                    // get the rounding to clip off the extra odd instance
                    size += ((occurances[word] / 2) * 4);
                    occurances[word] = 0;
                }
            }
            else {
                string reverse_word = word;
                char temp = reverse_word[0];
                reverse_word[0] = reverse_word[1];
                reverse_word[1] = temp;
                    
                #ifdef VERBOSE
                cout << word << " " << reverse_word << endl;
                #endif
                
                int a_occur = occurances[word];
                int b_occur = occurances[reverse_word];
                
                int min_occur = min(a_occur, b_occur);
                
                size += (min_occur * 4);
                
                occurances[word] -= min_occur;
                occurances[reverse_word] -= min_occur;
            }
        }
        
        return size;
    }
};

