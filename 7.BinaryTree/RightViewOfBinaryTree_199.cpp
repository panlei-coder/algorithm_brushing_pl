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

std::vector<int> rightSideView(TreeNode* root) {
    std::vector<std::vector<int>> result;
    std::vector<int> real_result;
    std::queue<TreeNode*> st;
    if (root != nullptr) {
        st.push(root);
    } else {
        return real_result;
    }

    TreeNode* node = nullptr;
    st.push(nullptr);
    int level = 0;
    result.push_back(std::vector<int>{});
    while (!st.empty()) {
        node = st.front();
        st.pop();
        if (node == nullptr) {
            if (st.empty()) {
                break;
            }
            node = st.front();
            st.pop();
            st.push(nullptr);
            level++;
            result.push_back(std::vector<int>{});
        }
        result[level].push_back(node->val);
        if (node->left) {
            st.push(node->left);
        } 
        if (node->right) {
            st.push(node->right);
        }
    }

    for (int i = 0; i < result.size(); i++) {
        real_result.push_back(result[i][result[i].size() - 1]);
    }

    return real_result;
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
    auto ret = rightSideView(root);

    return 0;
}