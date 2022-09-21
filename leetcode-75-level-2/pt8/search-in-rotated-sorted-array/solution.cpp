// #define VERBOSE

class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*
        // find the pivot index
        int pivot = -1;
        int prev = INT_MIN;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] < prev) {
                pivot = nums.size() - i;
            }
            prev = nums[i];
        }
        
        #ifdef VERBOSE
        cout << pivot << endl;
        #endif
        */
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {                
                return i;
            }
        }
        
        return -1;
    }
};

