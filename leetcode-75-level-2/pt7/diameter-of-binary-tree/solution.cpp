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
    int maximum = INT_MIN;
    
    int recursion(TreeNode* curr) {
        if (curr == NULL) return 0;
        
        int left = recursion(curr->left);
        int right = recursion(curr->right);
        
        if (left + right > maximum) {
            maximum = left + right;   
        }
        
        return max(left, right) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        
        recursion(root);
        
        return maximum;
    }
};

