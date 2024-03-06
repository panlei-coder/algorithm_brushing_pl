#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

std::vector<std::vector<int>> levelOrderOfN(Node* root) {
    std::vector<std::vector<int>> result;
    std::queue<Node*> st;
    if (root != nullptr) {
        st.push(root);
    } else {
        return result;
    }

    Node* node = nullptr;
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
        for (int i = 0; i < node->children.size(); i++) {
            st.push(node->children[i]);
        }
    }

    return result;
}

Node* constructNTree(const std::vector<int>& values) {
    if (values.empty()) {
        return nullptr;
    }

    Node* root = new Node(values[0]);
    std::queue<Node*> q;
    q.push(root);

    size_t i = 1;
    Node* current = nullptr;
    while (!q.empty() && i < values.size()) {
        current = q.front();
        q.pop();

        int children_count = 0;
        bool is_first = true;
        while (true) {
            if (i < values.size() && values[i] != INT32_MIN) {
                current->children.push_back(new Node(values[i]));
                q.push(current->children[children_count]);
                children_count++;
            } else if (is_first) {
                is_first = false;
            } else {
                break;
            }

            i++;
        }        
    }

    return root;
}

int main() {
    std::vector<int> values = {1, INT32_MIN, 3, 2, 4, INT32_MIN, 5, 6};
    Node* root = constructNTree(values);
    auto ret = levelOrderOfN(root);

    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            std::cout << ret[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}