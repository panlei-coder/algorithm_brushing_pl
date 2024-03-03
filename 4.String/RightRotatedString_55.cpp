#include <iostream>
#include <string>
#include <algorithm>

std::string RightRotatedString(std::string s, int position_from_end) {
    // int left = 0;
    // int right = s.size() - position_from_end;
    // char temp = ' ';
    // for (; right < s.size(); right++) {
    //     temp = s[right];
    //     for (int i = right - 1; i >= left; i--) {
    //         s[i + 1] = s[i];
    //     }
    //     s[left] = temp;
    //     left++;
    // }

    // return s;

    std::reverse(s.begin(), s.end());
    std::reverse(s.begin(), s.begin() + position_from_end);
    std::reverse(s.begin() + position_from_end, s.end());
    return s;
}

int main() {
    std::string s;
    int position_from_end;
    std::cin >> position_from_end;
    std::cin >> s;
    std::cout << RightRotatedString(s, position_from_end) << std::endl;

    return 0;
}