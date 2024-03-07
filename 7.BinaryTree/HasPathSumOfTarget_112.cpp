#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool getPathSum(TreeNode* node, int targetSum, int pathSum) {
    if (!node) {
        return false;
    }

    pathSum += node->val;
    int leftPathSum = pathSum;
    int rightPathSum = pathSum;
    int leftRet = getPathSum(node->left, targetSum, leftPathSum);
    int rightRet = getPathSum(node->right, targetSum, rightPathSum);
    if (!node->left && !node->right && (leftPathSum == targetSum || rightPathSum == targetSum)) {
        return true;
    }

    return leftRet || rightRet;
}

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) {
        return false;
    }

    int sum = 0;
    return getPathSum(root, targetSum, sum);
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
    std::vector<int> values = {1, 2, 3};
    int targetSum = 5;
    TreeNode* root = constructBinaryTree(values);
    auto ret = hasPathSum(root, targetSum);

    return 0;
}