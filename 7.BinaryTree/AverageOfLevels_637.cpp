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

std::vector<double> averageOfLevels(TreeNode* root) {
    std::vector<double> result;
    std::queue<TreeNode*> st;
    if (root != nullptr) {
        st.push(root);
    } else {
        return result;
    }

    TreeNode* node = nullptr;
    st.push(nullptr);
    int level_num = 0;
    double level_sum = 0;
    while (!st.empty()) {
        node = st.front();
        st.pop();
        if (node == nullptr) {
            result.push_back(level_sum / level_num);
            level_sum = 0;
            level_num = 0;
            if (st.empty()) {
                break;
            }
            node = st.front();
            st.pop();
            st.push(nullptr);
        }

        level_sum += node->val;
        level_num++;

        if (node->left) {
            st.push(node->left);
        } 
        if (node->right) {
            st.push(node->right);
        }
    }

    return result;
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
    auto ret = averageOfLevels(root);

    return 0;
}