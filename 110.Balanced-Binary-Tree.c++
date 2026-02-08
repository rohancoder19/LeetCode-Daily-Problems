//C++

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Helper function that returns the height of the tree if balanced, 
    // or -1 if the tree is unbalanced.
    int dfsHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        // Check left subtree
        int leftHeight = dfsHeight(root->left);
        if (leftHeight == -1) return -1; // Propagate unbalance

        // Check right subtree
        int rightHeight = dfsHeight(root->right);
        if (rightHeight == -1) return -1; // Propagate unbalance

        // Check difference
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        // Return height
        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        // If dfsHeight returns -1, it's not balanced. Otherwise, it is.
        return dfsHeight(root) != -1;
    }
};