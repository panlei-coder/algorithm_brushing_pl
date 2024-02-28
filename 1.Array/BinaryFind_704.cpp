#include <iostream>
#include <vector>

int BinaryFind(std::vector<int>& nums, int target) {
    int start = 0;
    int end = nums.size() - 1;
    int mid = (start + end) / 2;
    while (start <= end) {
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            start = mid + 1;
            mid = (start + end) / 2;
        } else if (nums[mid] > target) {
            end = mid - 1;
            mid = (start + end) / 2;
        }
    }

    return -1;
}

int main() {
    std::vector<int> nums;
    int target = 0;

    std::cout << "输入nums：" << std::endl;
    int temp = 0;
    while (std::cin >> temp && temp != -1) {
        nums.push_back(temp);
    }

    std::cout << "输入target：" << std::endl;
    std::cin >> target;

    int ret = BinaryFind(nums, target);
    std::cout << "输出：" << ret << std::endl;

    return 0;
}