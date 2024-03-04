#include <iostream>
#include <string>

bool repeatedSubstringPattern(std::string s) {
    int i = 0;
    for (int length = 1; length <= s.size() / 2; length++) {
        i = length;
        for (; i < s.size(); i++) {
            if (s[i] != s[i % length]) {
                break;
            }
        }

        if (i == s.size() && s.size() % length == 0) {
            return true;
        }                      
    }

    return false;
}

int main() {

    return 0;
}