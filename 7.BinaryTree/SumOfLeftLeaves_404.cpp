#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int sumOfLeftLeaves(TreeNode* root) {
    if (!root || (!root->left && !root->right)) {
        return 0;
    }

    int left_sum = sumOfLeftLeaves(root->left);
    if (root->left && !root->left->left && !root->left->right) {
        left_sum = root->left->val;
    }

    int right_sum = sumOfLeftLeaves(root->right);

    return left_sum + right_sum;
}

int main() {

    return 0;
}