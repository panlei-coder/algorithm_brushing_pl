#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void getCounter(TreeNode* node, int& num) {
    if (node == nullptr) {
        return;
    } 

    num++;
    getCounter(node->left, num);
    getCounter(node->right, num);
}

int countNodes(TreeNode* root) {
    int num = 0;
    if (root != nullptr) {
        num++;
    } else {
        return num;
    }

    getCounter(root->left, num);
    getCounter(root->right, num);

    return num;
}

int main() {

    return 0;
}