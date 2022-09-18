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
    void recursion(TreeNode* curr) {
        if (curr == NULL) return;
        
        TreeNode* swap = curr->left;
        curr->left = curr->right;
        curr->right = swap;
        
        recursion(curr->left);
        recursion(curr->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        recursion(root);
        return root;
    }
};

