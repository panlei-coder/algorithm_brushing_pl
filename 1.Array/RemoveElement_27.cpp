#include <iostream>
#include <vector>
#include <algorithm>

int RemoveElement(std::vector<int>& nums, int val) {
    int length = nums.size();
    int i = 0; // 快指针
    int j = 0; // 慢指针
    for (; i < length; i++) {
        if (nums[i] != val) {
            nums[j] = nums[i];
            j++;
        }
    }

    return j;
}

int main() {
    std::vector<int> nums;
    int val = 0;

    std::cout << "输入nums：" << std::endl;
    int temp = 0;
    while (std::cin >> temp && temp != -1) {
        nums.push_back(temp);
    }

    std::cout << "输入val：" << std::endl;
    std::cin >> val;

    int length = RemoveElement(nums, val);
    std::cout << "输出：" << length << std::endl;

    return 0;
}