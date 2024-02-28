#include <iostream>

typedef struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
}ListNode;

ListNode* PairwiseSwapNodes(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    ListNode* left = head;
    ListNode* right = head->next;
    ListNode* temp = nullptr;
    ListNode* prev = nullptr;
    head = nullptr;
    while (left && right) {
        temp = right->next;
        left->next = right->next;
        right->next = left;
        if (prev) {
            prev->next = right;
        }

        if (!head) {
            head = right;
        }

        prev = left;
        left = temp;
        if (temp) {
            right = temp->next;
        } else {
            right = nullptr;
        }
    }

    return head;
}

int main() {
    ListNode* head(nullptr);
    ListNode* tail(nullptr);
    
    std::cout << "输入链表数据：" << std::endl;
    int temp = 0;
    while (std::cin >> temp && temp != -1) {
        ListNode* new_node = new ListNode(temp, nullptr);
        if (!head) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    auto new_head = PairwiseSwapNodes(head);
    while (new_head) {
        std::cout << new_head->val << " ";
        ListNode* temp = new_head;
        new_head = new_head->next;
    }
    std::cout << std::endl;

    return 0;
}