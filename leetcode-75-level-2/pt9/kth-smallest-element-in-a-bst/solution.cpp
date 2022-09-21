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

class Solution {
public:
    int val = 0; 
    int index = 0;
    int max_index = 0;
    
    // do an exhaustive depth first search
    void convertVals(TreeNode* curr) {
        if (curr->left != NULL) {
            convertVals(curr->left);
        }
        if (index++ == max_index) {
            val = curr->val;
            return;
        }
        if (curr->right != NULL) {
            convertVals(curr->right);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        max_index = k-1;
        convertVals(root);
        return val;
    }
};

