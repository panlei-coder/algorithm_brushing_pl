#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    /* 使用hash法超时了 */
    // std::sort(nums.begin(), nums.end());

    // std::multimap<int, std::vector<int>> nums_map;
    // for (int i = 0; i < nums.size(); i++) {
    //     for (int j = i + 1; j < nums.size() - 1; j++) {
    //         nums_map.insert(std::pair<int, std::vector<int>>(nums[i] + nums[j], std::vector<int>{i, j, j + 1}));
    //     }
    // }

    // std::vector<std::vector<int>> result;
    // for (auto it = nums_map.begin(); it != nums_map.end(); it++) {
    //     for (int k = it->second[2]; k < nums.size(); k++) {
    //         if ((it->first + nums[k]) == 0) {
    //             result.push_back(std::vector<int>{nums[it->second[0]], nums[it->second[1]], nums[k]});
    //         }
    //     }
    // }

    // /* 需要去重，但是时间复杂度就会增加 */
    // for (int i = 0; i < result.size(); i++) {
    //     for (int j = 0; j < result.size(); j++) {
    //         if (result[i][0] == result[j][0] && result[i][1] == result[j][1]) {
    //             result.erase(result.begin() + j);
    //             j--;
    //         }
    //     }
    // }

    // return result;

    /* 双指针法 */
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> result;
    int left = 0;
    int right = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            break;
        }

        // 第一个数也要去重
        if (i > 0 && nums[i - 1] == nums[i]) {
            continue;
        }

        left = i + 1;
        right = nums.size() - 1;
        while (left < right) {
            sum = nums[i] + nums[left] + nums[right];
            if (sum < 0) {
                left++;
            } else if (sum > 0) {
                right--;
            } else {
                result.push_back(std::vector<int>{nums[i], nums[left], nums[right]});
                while (left + 1 < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                while (left < right - 1 && nums[right] == nums[right - 1]) {
                    right--;
                }

                left++;
                right--;
            }
        }
    }

    return result;
}

int main() {

    return 0;
}
