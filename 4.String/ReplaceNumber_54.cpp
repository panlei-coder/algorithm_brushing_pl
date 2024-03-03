#include <iostream>
#include <string>

std::string replaceNumber(std::string s) {
    std::string s_number;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s_number.append(std::string(1, s[i]));
        } else {
            s_number.append("number");
        }
    }

    return s_number;
}

int main() {
    std::string s;
    std::cin >> s;
    auto ret = replaceNumber(s);
    std::cout << ret << std::endl;

    return 0;
}