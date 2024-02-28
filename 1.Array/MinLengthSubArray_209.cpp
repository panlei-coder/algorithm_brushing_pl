#include <iostream>
#include <vector>

int MinLengthSubArray(std::vector<int>& nums, int s) {
    // 1、针对每一个步长step的子串都求出和，然后找到能够满足条件的子串，这种思想的复杂度太高了
    // int length = nums.size();
    // int step = 1;
    // int sum = 0;
    // for (; step <= length; step++) {
    //     for (int i = 0; i < length; i++) {
    //         if (i + step <= length) {
    //             for (int j = i; j - i < step && j < length; j++) {
    //                 sum += nums[j];
    //             }

    //             if (sum >= s) {
    //                 return step;
    //             }
    //             sum = 0;
    //         }        
    //     }
    // }

    // 2、求从某个位置开始的，能够满足条件的子串都有哪些，然后找到满足条件的子串中长度最短的那个
    // int length = nums.size();
    // int sum = 0;
    // int minLength = INT32_MAX;
    // for (int i = 0; i < length; i++) {
    //     for (int j = i; j < length; j++) {
    //         sum += nums[j];
    //         if (sum >= s) {
    //             int subLength = j - i + 1;
    //             minLength = minLength > subLength ? subLength : minLength;
    //             break;
    //         }
    //     }
    //     sum = 0;
    // }

    // minLength = minLength == INT32_MAX ? 0 : minLength;
    // return minLength;

    // 3、前两种解法都会超时，这里主要考察的滑动窗口法，其实也可以理解为双指针法
    int length = nums.size();
    int minLength = INT32_MAX;
    int subLength = 0;
    int sum = 0;
    int left = 0;
    for (int right = 0; right < length; right++) {
        sum += nums[right];
        while(sum >= s) {
            subLength = right - left + 1;
            minLength = minLength < subLength ? minLength : subLength;
            sum -= nums[left++];
        }
    }

    minLength = minLength == INT32_MAX ? 0 : minLength;
    return minLength;
}

int main() {
    std::vector<int> nums;
    int s = 0;

    std::cout << "输入数组：" << std::endl;
    int temp = 0;
    while (std::cin >> temp && temp != -1) {
        nums.push_back(temp);
    }    
    std::cout << "输入整数s：" << std::endl;
    std::cin >> s;

    auto ret = MinLengthSubArray(nums, s);
    std::cout << ret << std::endl;

    return 0;
}