#include <iostream>
#include <vector>
#include <map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::map<int, std::vector<int>> nums_map;
    for (int i = 0;i < nums.size(); i++) {
        if (nums_map.find(nums[i]) != nums_map.end()) {
            nums_map[nums[i]].push_back(i);
        } else {
            std::vector<int> vec;
            vec.push_back(i);
            nums_map[nums[i]] = std::move(vec);
        }        
    }

    int temp = 0;
    std::map<int, std::vector<int>>::iterator it;
    for (int i = 0;i < nums.size(); i++) {
        temp = target - nums[i];
        it = nums_map.find(temp);
        if (it != nums_map.end()) {
            for (int j = 0;j < it->second.size(); j++) {
                if (it->second[j] != i) {
                    return std::vector<int>{i, it->second[j]};
                }
            }
        }
    }

    return std::vector<int>{};
}

int main() {
    int target = 0;
    std::vector<int> nums;

    std::cout << "输入数组：" << std::endl;
    int temp = 0;
    while (std::cin >> temp && temp != -1) {
        nums.push_back(temp);
    }

    std::cout << "输入target：" << std::endl;
    std::cin >> target;

    auto ret = twoSum(nums, target);
    for (int i = 0;i < ret.size(); i++) {
        std::cout << ret[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}