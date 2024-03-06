#include <iostream>
#include <vector>
#include <cstdlib>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool getDepth(TreeNode* node, int& depth) {
    if (node == nullptr) {
        return true;
    } 

    depth++;
    int left_depth = 0;
    int right_depth = 0;
    auto left_is_balanced = getDepth(node->left, left_depth);
    auto right_is_balanced = getDepth(node->right, right_depth);
    depth += left_depth > right_depth ? left_depth : right_depth;
    if (left_is_balanced && right_is_balanced && abs(left_depth - right_depth) <= 1) {
        return true;
    }

    return false;
}

bool isBalanced(TreeNode* root) {
    if (!root) {
        return true;
    } 

    int left_depth = 0;
    int right_depth = 0;
    auto left_is_balanced = getDepth(root->left, left_depth);
    auto right_is_balanced = getDepth(root->right, right_depth);
    if (left_is_balanced && right_is_balanced && abs(left_depth - right_depth) <= 1) {
        return true;
    }

    return false;
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
    std::vector<int> values = {1, 2, 2, 3, 3, INT32_MIN, INT32_MIN, 4};
    TreeNode* root = constructBinaryTree(values);
    auto ret = isBalanced(root);

    return 0;
}