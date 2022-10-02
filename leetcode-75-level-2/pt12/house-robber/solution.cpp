class Solution {
public:
    /*
    // Brute Force Solution
    int recursion(vector<int>& nums, int index) {
        if (index >= nums.size()) {
            return 0;
        }
        return max(nums[index] + recursion(nums, index+2), recursion(nums, index+1));
    }
    
    int rob(vector<int>& nums) {
        int index = 0;
        return recursion(nums, index);
    }
    */
    
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        vector<int> dp(nums.size(), -1);
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        
        return dp[nums.size()-1];
    }
};

