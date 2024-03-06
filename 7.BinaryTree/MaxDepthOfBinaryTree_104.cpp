#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// int getDepth(TreeNode* node, int depth) {
//     if (node == nullptr) {
//         return depth;
//     } 

//     depth++;
//     int left_depth = getDepth(node->left, depth);
//     int right_depth = getDepth(node->right, depth);

//     return left_depth > right_depth ? left_depth : right_depth;
// }

// int maxDepth(TreeNode* root) {
//     int max_depth = getDepth(root, 0);

//     return max_depth;
// }

// 统一成这种写法吧
int maxDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }

    if (!root->left) {
        return maxDepth(root->right) + 1;
    } else if (!root->right) {
        return maxDepth(root->left) + 1;
    }

    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

TreeNode* constructBinaryTree(const std::vector<int>& values) {
    if (values.empty()) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(values[0]);
    std::queue<TreeNode*> q;
    q.push(root);

    size_t i = 1;
    while (!q.empty() && i < values.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (values[i] != INT32_MIN) {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++;

        if (i < values.size() && values[i] != INT32_MIN) {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int main() {
    std::vector<int> values = {3, 9, 20, INT32_MIN, INT32_MIN, 15, 7};
    TreeNode* root = constructBinaryTree(values);
    auto ret = maxDepth(root);

    return 0;
}