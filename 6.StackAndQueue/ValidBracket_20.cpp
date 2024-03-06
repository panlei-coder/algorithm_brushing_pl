#include <iostream>
#include <queue>
#include <stack>
#include <string>

bool isValid(std::string s) {
    std::queue<char> bracket_queue;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == ')' || s[i] == '{' || 
            s[i] == '}' || s[i] == '[' || s[i] == ']') {
                bracket_queue.push(s[i]);
        }
    }

    std::stack<char> bracket_temp_stack;
    int size = bracket_queue.size();
    char front_bracket = ' ';
    char top_bracket = ' ';
    for (int i = 0; i < size; i++) {
        front_bracket = bracket_queue.front();
        bracket_queue.pop();
        if (front_bracket == '(' || front_bracket == '{' || front_bracket == '[') {
            bracket_temp_stack.push(front_bracket);
        } else {
            if (bracket_temp_stack.empty()) {
                return false;
            }
            top_bracket = bracket_temp_stack.top();
            if ((top_bracket == '(' && front_bracket == ')') || (top_bracket == '{' && 
                front_bracket == '}') || (top_bracket == '[' && front_bracket == ']')) {
                bracket_temp_stack.pop();
            } else {
                return false;
            }
        }       
    }

    if (!bracket_temp_stack.empty()) {
        return false;
    }

    return true;
}

int main() {

    return 0;
}