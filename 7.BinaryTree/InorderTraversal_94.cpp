#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<int> inorderTraversal(TreeNode* root) {
    std::stack<TreeNode*> st;
    std::vector<int> result;
    if (root == nullptr) { 
        return result;
    }

    TreeNode* node = root;
    while (node != nullptr || !st.empty()) {
        if (node != nullptr) {
            st.push(node);
            node = node->left;
        } else {
            node = st.top();
            st.pop();
            result.push_back(node->val);
            node = node->right;
        }
    }

    return result;
}

int main() {

    return 0;
}