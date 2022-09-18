/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// #define VERBOSE

class Solution {
public:
    int validPaths(TreeNode* curr, int targetSum, long int runningSum) {
        if (curr == NULL) {
            return 0;
        }
        
        int ret = 0;
        
        runningSum += curr->val;
        
        if (runningSum == targetSum) {
            ret += 1;
        }

        ret += validPaths(curr->left, targetSum, runningSum);
        ret += validPaths(curr->right, targetSum, runningSum);
        
        return ret;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return 0;
        }
        
        // get the number of valid paths starting at current node
        int ret = validPaths(root, targetSum, 0);
        
        #ifdef VERBOSE
        cout << ret << endl;
        #endif
        
        // go to the next nodes
        ret += pathSum(root->left, targetSum);
        ret += pathSum(root->right, targetSum);
        
        return ret;
    }
};

