#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int getBottomLeftValue(TreeNode* root, int& level) {
    if (!root) {
        return 0;
    }

    level++;
    int left_level = level;
    int left_value = getBottomLeftValue(root->left, left_level);
    if (root->left && !root->left->left && !root->left->right) {
        left_value = root->left->val;
    }

    int right_level = level;
    int right_value = getBottomLeftValue(root->right, right_level);

    level = left_level >= right_level ? left_level : right_level;
    return left_level >= right_level ? left_value : right_value;
}

int findBottomLeftValue(TreeNode* root) {
    if (!root) {
        return 0;
    }

    int left_level = 0;
    int left_value = getBottomLeftValue(root->left, left_level);
    int right_level = 0;
    int right_value = getBottomLeftValue(root->right, right_level);
    
    return left_level >= right_level ? left_value : right_value;
}

int main() {

    return 0;
}