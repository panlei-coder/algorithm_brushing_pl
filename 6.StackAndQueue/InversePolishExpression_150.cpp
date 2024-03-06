#include <iostream>
#include <stack>
#include <vector>
#include <string>

int evalRPN(std::vector<std::string>& tokens) {
    std::stack<int> tokens_stack;
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
            int second_num = tokens_stack.top();
            tokens_stack.pop();
            int first_num = tokens_stack.top();
            tokens_stack.pop();
            int result = 0;
            if (tokens[i] == "+") {
                result = first_num + second_num;
            } else if (tokens[i] == "-") {
                result = first_num - second_num;
            } else if (tokens[i] == "*") {
                result = first_num * second_num;
            } else {
                result = first_num / second_num;
            }
            
            tokens_stack.push(result);
        } else {
            tokens_stack.push(std::stoi(tokens[i]));
        }
    }

    return tokens_stack.top();
}

int main() {

    return 0;
}