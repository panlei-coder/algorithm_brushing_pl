#include <iostream>
#include <stack>
#include <string>

std::string removeDuplicates(std::string s) {
    if (s.size() == 0) {
        return s;
    }

    std::stack<char> s_stack;
    s_stack.push(s[0]);
    char top = ' ';
    for (int i = 1; i < s.size(); i++) {
        if (!s_stack.empty()) {
            top = s_stack.top();
            if (top == s[i]) {
                s_stack.pop();
                continue;
            }
        }
        
        s_stack.push(s[i]);
    }

    int size = s_stack.size();
    s.resize(size);
    for (int i = size - 1; i >= 0; i--) {
        top = s_stack.top();
        s_stack.pop();
        s[i] = top;
    }

    return s;
}

int main() {

    return 0;
}