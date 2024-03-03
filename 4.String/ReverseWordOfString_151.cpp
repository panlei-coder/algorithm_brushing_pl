#include <iostream>
#include <string>

void reverseString(std::string& s, int left, int right) {
    char temp = ' ';
    while (left < right) {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

std::string reverseWords(std::string s) {
    int slow = 0;
    int fast = 0;
    int count_blank_space = 0;
    while (s[fast] == ' ') {
        fast++;
    }

    for (; fast < s.size(); fast++) {
        if (s[fast] != ' ') {
            if (count_blank_space >= 1) {
                s[slow] = ' ';
                slow++;
                count_blank_space = 0;
            }
            s[slow] = s[fast];
            slow++;
        } else {
            count_blank_space++;
        }
    }

    s.resize(slow);
    int left = 0;
    int right = 0;
    for (int i = 0; i <= s.size(); i++) {
        if (s[i] == ' ' || i == s.size()) {
            right = i - 1;
            reverseString(s, left, right);
            left = i + 1;
        }
    }
    reverseString(s, 0, s.size() - 1);

    return s; 
}

int main() {
    std::cout << reverseWords("the sky is blue") << std::endl;

    return 0;
}
