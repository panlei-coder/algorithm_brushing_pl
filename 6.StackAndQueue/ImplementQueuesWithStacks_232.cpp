#include <iostream>
#include <stack>

class MyQueue {
public:
    MyQueue() {}
    
    void push(int x) {
        stack_first.push(x);
    }
    
    int pop() {
        if (stack_second.empty()) {
            int size = stack_first.size();
            int temp = 0;
            for (int i = 0; i < size; i++) {
                temp = stack_first.top();
                stack_first.pop();
                stack_second.push(temp);
            }
        }
        int temp = stack_second.top();
        stack_second.pop();
        return temp;
    }
    
    int peek() {
        if (!stack_second.empty()) {
            return stack_second.top();
        } 

        int size = stack_first.size();
        int temp = 0;
        for (int i = 0; i < size; i++) {
            temp = stack_first.top();
            stack_first.pop();
            stack_second.push(temp);
        }

        return stack_second.top();
    }
    
    bool empty() {
        if (stack_first.empty() && stack_second.empty()) {
            return true;
        }

        return false;
    }
    
private:
    std::stack<int> stack_first;
    std::stack<int> stack_second;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */