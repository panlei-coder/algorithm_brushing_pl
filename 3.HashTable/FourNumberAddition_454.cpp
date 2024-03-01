#include <iostream>
#include <vector>
#include <unordered_map>

int fourSumCount(std::vector<int>& nums1, std::vector<int>& nums2, std::vector<int>& nums3, std::vector<int>& nums4) {
    std::unordered_map<int, int> sums_12;
    std::unordered_map<int, int> sums_34;
    for (int i = 0; i < nums1.size(); i++) {
        for (int j = 0; j < nums2.size(); j++) {
            sums_12[nums1[i] + nums2[j]]++;
        }
    }

    for (int i = 0; i < nums3.size(); i++) {
        for (int j = 0; j< nums4.size(); j++) {
            sums_34[nums3[i] + nums4[j]]++;
        }
    }

    int count = 0;
    int temp = 0;
    for (auto it_12 = sums_12.begin(); it_12 != sums_12.end(); it_12++) {
        temp = 0 - it_12->first;
        auto it_34 = sums_34.find(temp);
        if (it_34 != sums_34.end()) {
            count += it_12->second * it_34->second;
        }
    }

    return count;
}

int main() {
    std::vector<int> nums1;
    std::vector<int> nums2;
    std::vector<int> nums3;
    std::vector<int> nums4;

    std::cout << "输入数组nums1：" << std::endl;
    int temp = 0;
    while (std::cin >> temp && temp != -1) {
        nums1.push_back(temp);
    }

    std::cout << "输入数组nums2：" << std::endl;
    while (std::cin >> temp && temp != -1) {
        nums2.push_back(temp);
    }

    std::cout << "输入数组nums3：" << std::endl;
    while (std::cin >> temp && temp != -1) {
        nums3.push_back(temp);
    }

    std::cout << "输入数组nums4：" << std::endl;
    while (std::cin >> temp && temp != -1) {
        nums4.push_back(temp);
    }

    auto count = fourSumCount(nums1, nums2, nums3, nums4);
    std::cout << count << std::endl;

    return 0;
}