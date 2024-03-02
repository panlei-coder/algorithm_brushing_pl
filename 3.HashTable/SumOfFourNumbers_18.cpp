#include <iostream>
#include <vector>
#include <algorithm>

/* 类比三数之和_15，使用双指针法 */
std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    int left = 0;
    int right = 0;
    int64_t sum = 0;
    std::vector<std::vector<int>> result;
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0  && nums[i-1] == nums[i]) {
            continue;
        }

        for (int j = i + 1; j < nums.size(); j++) {
            if (j > i + 1 && nums[j-1] == nums[j]) {
                continue;
            }

            left = j + 1;
            right = nums.size() - 1;
            while (left < right) {
                sum = 0;
                sum += nums[i];
                sum += nums[j];
                sum += nums[left];
                sum += nums[right];
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    result.push_back(std::vector<int>{nums[i], nums[j], nums[left], nums[right]});
                    while (left + 1 < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left + 1 < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }
    }

    return result;
}

int main() {

    return 0;
}