#include <iostream>

typedef struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
}ListNode;

ListNode* DeletePenultimateNTHNodes(ListNode* head, int n) {
    if (!head || (!head->next && n == 1)) {
        return nullptr;
    }

    ListNode* fast = head;
    ListNode* slow = head;
    while (n > 0) {
        if (!fast) {
            break;
        }

        fast = fast->next;
        n--;
    }

    if (n > 0) {
        return head;
    } else if (!fast && n == 0) {
        return head->next;
    }

    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    ListNode* temp = slow->next;
    slow->next = temp->next;

    return head;
}

int main() {
    ListNode* head(nullptr);
    ListNode* tail(nullptr);
    int n = 0;
    
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

    std::cout << "输入整数n：" << std::endl;
    std::cin >> n;

    auto new_head = DeletePenultimateNTHNodes(head, n);
    while (new_head) {
        std::cout << new_head->val << " ";
        ListNode* temp = new_head;
        new_head = new_head->next;
    }
    std::cout << std::endl;

    return 0;
}