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
    int height(TreeNode* curr, int depth = 0) {
        if (curr == NULL) {
            return depth;
        }
        depth++;
        return max(height(curr->left, depth), height(curr->right, depth));
    }
    
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        
        if (abs(height(root->left, 0) - height(root->right)) > 1) {
            return false;
        }
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

