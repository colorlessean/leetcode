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
class BSTIterator {
private:
    vector<int> values;
    int i = -1;
    void init(TreeNode* root) {
        if (root == NULL) return;
        init(root->left);
        values.push_back(root->val);
        init(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        init(root);
    }
    
    int next() {
        return values[++i];
    }
    
    bool hasNext() {
        return i+1<values.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

