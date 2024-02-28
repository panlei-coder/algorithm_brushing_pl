#include <iostream>
#include <list>

typedef struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
}ListNode;

// 实现的是不带头节点的链表
ListNode* RemoveListElement(ListNode* head, int val) {
    ListNode* next = head;
    ListNode* prev = nullptr;
    while (next != nullptr) {
        if (next->val == val) {
            if (next == head) {
                head = head->next;
                delete next;
                next = head;
            } else {
                ListNode* temp = next;
                prev->next = next->next;
                next = next->next;
                delete temp;
                temp = nullptr;
            }
        } else {
            next = next->next;
            if (!prev) {
                prev = head;
            } else {
                prev = prev->next;
            }
        }
    }

    return head;
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

    std::cout << "输入val：" << std::endl;
    std::cin >> val;

    auto new_head = RemoveListElement(head, val);
    while (new_head) {
        std::cout << new_head->val << " ";
        ListNode* temp = new_head;
        new_head = new_head->next;
    }
    std::cout << std::endl;

    return 0;
}