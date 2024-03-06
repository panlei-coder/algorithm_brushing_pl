#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<int> PostorderTraversal(TreeNode* root) {
    std::stack<TreeNode*> st;
    std::vector<int> result;
    if (root == nullptr) { 
        return result;
    }

    TreeNode* node = root;
    st.push(node);
    while (!st.empty()) {
        node = st.top();
        st.pop();
        result.push_back(node->val);
        if (node->left) {
            st.push(node->left);
        }
        if (node->right) {
            st.push(node->right);
        }
    }
    std::reverse(result.begin(), result.end());

    return result;
}

int main() {

    return 0;
}