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

std::string reverseStringII(std::string s, int k) {
    int length = s.size();
    int count = length / (k * 2);
    int left = 0;
    int right = 0;
    for (int i = 0; i < count; i++) {
        left = 2 * k * i;
        right = left + k - 1;
        reverseString(s, left, right);
    }    

    if (length - k * 2 * count < k) {
        left = 2 * k * count;
        right = length - 1;
        reverseString(s, left, right);
    } else {
        left = 2 * k * count;
        right = left + k - 1;
        reverseString(s, left, right);
    }

    return s;
}

int main() {

}