//C++

class Solution {
public:
    unordered_map<TreeNode*, int> depth;
    int maxDepth = 0;

    void dfs(TreeNode* node, TreeNode* parent) {
        if (!node) return;

        depth[node] = (parent ? depth[parent] : -1) + 1;
        maxDepth = max(maxDepth, depth[node]);

        dfs(node->left, node);
        dfs(node->right, node);
    }

    TreeNode* answer(TreeNode* node) {
        if (!node || depth[node] == maxDepth)
            return node;

        TreeNode* L = answer(node->left);
        TreeNode* R = answer(node->right);

        if (L && R) return node;
        return L ? L : R;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root, nullptr);
        return answer(root);
    }
};
