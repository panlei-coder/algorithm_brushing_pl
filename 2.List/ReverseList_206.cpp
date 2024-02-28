#include <iostream>

typedef struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
}ListNode;

ListNode* ReverseList(ListNode* head) {
    if (!head) {
        return head;
    }

    ListNode* p = head;
    ListNode* new_head = nullptr;
    ListNode* temp = nullptr;
    while (p) {
        if (!new_head) {
            new_head = p;
            p = p->next;
            new_head->next = nullptr;
        } else {
            temp = p->next;
            p->next = new_head;
            new_head = p;
            p = temp;
        }
    }

    return new_head;
}

int main() {
    ListNode* head(nullptr);
    ListNode* tail(nullptr);
    int val = 0;
    
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
    
    auto new_head = ReverseList(head);
    while (new_head) {
        std::cout << new_head->val << " ";
        ListNode* temp = new_head;
        new_head = new_head->next;
    }
    std::cout << std::endl;

    return 0;
}