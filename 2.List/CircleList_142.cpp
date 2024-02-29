#include <iostream>

typedef struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
}ListNode;

ListNode* CircleList(ListNode* head) {
    if (!head || !head->next) {
        return nullptr;
    }

    ListNode* fast = head->next;
    ListNode* slow = head;

    while (true) {
        if (fast == slow) {
            break;
        }

        if (fast->next && fast->next->next && slow->next) {
            fast = fast->next->next;
            slow = slow->next;
        } else {
            return nullptr;
        }
    }

    ListNode* index_1 = head;
    ListNode* index_2 = fast->next;
    while (true) {
        if (index_1 == index_2) {
            break;
        }

        index_1 = index_1->next;
        index_2 = index_2->next;
    }

    return index_1;
}

int main() {
    ListNode* head(nullptr);
    ListNode* tail(nullptr);
    int pos = 0;
    
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

    std::cout << "输入整数pos：" << std::endl;
    std::cin >> pos;

    ListNode* circle_node = head;
    while (pos > 0) {
        circle_node = circle_node->next;
        pos--;
    }
    tail->next = circle_node;

    auto new_head = CircleList(head);
    std::cout << new_head->val << std::endl;

    return 0;
}