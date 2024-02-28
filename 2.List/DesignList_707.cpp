#include <iostream>
#include <list>

// 带头节点的链表
class MyLinkedList {
public:
    typedef struct ListNode {
        int val;
        ListNode* next;

        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    }ListNode;

    MyLinkedList() {
        head_ = new ListNode();
    }
    
    int get(int index) {
        ListNode* p = head_;
        while (index >= 0) {
            if (!p) {
                break;
            }

            p = p->next;
            index--;
        }

        if (!p) {
            return -1;
        }

        return p->val;
    }
    
    void addAtHead(int val) {
        ListNode* new_node = new ListNode(val);
        if (!head_) {
            head_->next = new_node;
        } else {
            new_node->next = head_->next;
            head_->next = new_node;
        }
    }
    
    void addAtTail(int val) {
        ListNode* new_node = new ListNode(val);
        ListNode* p = head_;
        while (p->next) {
            p = p->next;
        }

        p->next = new_node;
    }
    
    void addAtIndex(int index, int val) {
        ListNode* new_node = new ListNode(val);
        if (index < 0) {
            head_->next = new_node;
        }

        ListNode* p = head_;
        while (index > 0) {
            if (!p) {
                break;
            }

            p = p->next;
            index--;
        }

        if (!p || index > 0) {
            return;
        } else {
            new_node->next = p->next;
            p->next = new_node;
        }
    }
    
    void deleteAtIndex(int index) {
        ListNode* p = head_;
        while (index > 0) {
            if (!p) {
                break;
            }

            p = p->next;
            index--;
        }

        if (!p || !p->next || index > 0) {
            return;
        } else {
            ListNode* deleted_node = p->next;
            p->next = deleted_node->next;
            delete deleted_node;
            deleted_node = nullptr;
        }
    }

    void printList() {
        ListNode* p = head_->next;
        while (p) {
            std::cout << p->val << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }

private:
    ListNode* head_{nullptr};
};

int main() {
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(2);
    obj->deleteAtIndex(1);
    obj->addAtHead(2);
    obj->addAtHead(7);
    obj->addAtHead(3);
    obj->addAtHead(2);
    obj->addAtHead(5);
    obj->addAtTail(5);
    obj->printList();
    obj->get(5);
    obj->deleteAtIndex(6);
    obj->printList();
    obj->deleteAtIndex(4);
    obj->printList();

    return 0;
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */