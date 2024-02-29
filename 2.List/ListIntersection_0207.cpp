#include <iostream>

typedef struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
}ListNode;

ListNode* ListIntersection(ListNode* headA, ListNode* headB) {
    int lengthA = 0;
    int lengthB = 0;
    ListNode* p = headA;
    while (p) {
        lengthA++;
        p = p->next;
    } 

    p = headB;
    while (p) {
        lengthB++;
        p = p->next;
    }

    ListNode* pA = headA;
    ListNode* pB = headB;
    int countAB = lengthA > lengthB ? (lengthA - lengthB) : (lengthB - lengthA);
    if (lengthA > lengthB) {
        while (countAB > 0) {
            pA = pA->next;
            countAB--;
        }
    } else {
        while (countAB > 0) {
            pB = pB->next;
            countAB--;
        }
    }

    while (pA && pB) {
        if (pA == pB) {
            break;
        }
        pA = pA->next;
        pB = pB->next;
    }

    return pA;
}

int main() {
    ListNode* headA(nullptr);
    ListNode* headB(nullptr);
    ListNode* tail(nullptr);
    int intersectVal = 0;
    int skipA = 3;
    int skipB = 1;
    
    std::cout << "输入整数intersectVal：" << std::endl;
    std::cin >> intersectVal;

    std::cout << "输入链表A数据：" << std::endl;
    int temp = 0;
    while (std::cin >> temp && temp != -1) {
        ListNode* new_node = new ListNode(temp, nullptr);
        if (!headA) {
            headA = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    std::cout << "输入链表B数据：" << std::endl;
    while (std::cin >> temp && temp != -1) {
        ListNode* new_node = new ListNode(temp, nullptr);
        if (!headB) {
            headB = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    std::cout << "输入整数skipA：" << std::endl;
    std::cin >> skipA;
    std::cout << "输入整数skipB：" << std::endl;
    std::cin >> skipB;

    ListNode* pA = headA;
    ListNode* pB = headB;
    while (skipA > 1) {
        pA = pA->next;
        skipA--;
    }
    while (skipB > 1) {
        pB = pB->next;
        skipB--;
    }
    pA->next = pB->next;

    auto result = ListIntersection(headA, headB);
    if (result) {
        std::cout << result->val << std::endl;
    } else {
        std::cout << "null" << std::endl;
    }

    return 0;
}