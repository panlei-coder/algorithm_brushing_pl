#include <iostream>
#include <queue>

class MyStack {
public:
    MyStack() {}
    
    void push(int x) {
        if (queue_first.empty() && queue_second.empty()) {
            queue_first.push(x);
        } else if (!queue_first.empty()) {
            queue_first.push(x);
        } else {
            queue_second.push(x);
        }
    }
    
    int pop() {
        int temp = -1;
        int size = 0;
        if (!queue_first.empty()) {
            size = queue_first.size();
            for (int i = 0; i < size - 1; i++) {
                temp = queue_first.front();
                queue_second.push(temp);
                queue_first.pop();
            }
            temp = queue_first.front();
            queue_first.pop();
        } else if (!queue_second.empty()) {
            size = queue_second.size();
            for (int i = 0; i < size - 1; i++) {
                temp = queue_second.front();
                queue_first.push(temp);
                queue_second.pop();
            }
            temp = queue_second.front();
            queue_second.pop();
        }

        return temp;
    }
    
    int top() {
        int temp = -1;
        int size = 0;
        if (!queue_first.empty()) {
            size = queue_first.size();
            for (int i = 0; i < size; i++) {
                temp = queue_first.front();
                queue_second.push(temp);
                queue_first.pop();
            }
        } else if (!queue_second.empty()) {
            size = queue_second.size();
            for (int i = 0; i < size; i++) {
                temp = queue_second.front();
                queue_first.push(temp);
                queue_second.pop();
            }
        }

        return temp;
    }
    
    bool empty() {
        if (queue_first.empty() && queue_second.empty()) {
            return true;
        }

        return false;
    }

private:
    std::queue<int> queue_first;
    std::queue<int> queue_second;
};


int main() {

    return 0;
}