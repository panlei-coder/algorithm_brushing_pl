#include <iostream>
#include <vector>
#include <string>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void getTreePaths(TreeNode* node, std::vector<std::string>& tree_paths, std::string path) {
    if (node->left  == nullptr && node->right == nullptr) {
        tree_paths.push_back(path);
        return;
    }

    if (node->left) {
        std::string left_path(path + "->" + std::to_string(node->left->val));
        getTreePaths(node->left, tree_paths, left_path);
    } 

    if (node->right) {
        std::string right_path(path + "->" + std::to_string(node->right->val));
        getTreePaths(node->right, tree_paths, right_path);
    }
}

std::vector<std::string> binaryTreePaths(TreeNode* root) {
    std::vector<std::string> tree_paths;
    if (root == nullptr) {
        return tree_paths;
    }

    std::string path(std::to_string(root->val));
    getTreePaths(root, tree_paths, path);

    return tree_paths;
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
    std::vector<int> values = {1, 2, 3, INT32_MIN, 5};
    TreeNode* root = constructBinaryTree(values);
    auto ret = binaryTreePaths(root);


    return 0;
}