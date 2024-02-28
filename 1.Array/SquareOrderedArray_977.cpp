#include <iostream>
#include <vector>

std::vector<int> SquareOrderedArray(std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    int index = right;
    std::vector<int> result(right + 1);
    while (left <= right) {
        if (nums[left] * nums[left] < nums[right] * nums[right]) {
            result[index--] = nums[right] * nums[right];
            right--;
        } else {
            result[index--] = nums[left] * nums[left];
            left++;
        }
    }

    return result;
}

int main () {
    std::vector<int> nums;
    
    std::cout << "输入非递减排序的数组：" << std::endl;
    int temp = 0;
    while (std::cin >> temp && temp != -1) {
        nums.push_back(temp);
    }

    auto result = SquareOrderedArray(nums);
    int length = result.size();
    for (int i = 0; i < length; i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}