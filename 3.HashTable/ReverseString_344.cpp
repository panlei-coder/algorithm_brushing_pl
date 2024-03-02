#include <iostream>
#include <vector>

void reverseString(std::vector<char>& s) {
    int left = 0;
    int right = s.size() - 1;
    char temp = ' ';
    while (left < right) {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

int main() {

    return 0;
}