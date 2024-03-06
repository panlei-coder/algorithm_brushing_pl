#include <iostream>
#include <queue>

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
    std::queue<Node*> st;
    if (root != nullptr) {
        st.push(root);
    } else {
        return root;
    }

    Node* node = nullptr;
    st.push(nullptr);
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
        }
        node->next = st.front();
        if (node->left) {
            st.push(node->left);
        } 
        if (node->right) {
            st.push(node->right);
        }
    }

    return root;
}

int main() {

    return 0;
}