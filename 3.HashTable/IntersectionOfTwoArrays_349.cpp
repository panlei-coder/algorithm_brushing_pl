#include <iostream>
#include <vector>
#include <map>

std::vector<int> IntersectionOfTwoArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::map<int, int> nums1_map;
    for (int i = 0;i < nums1.size(); i++) {
        if (nums1_map.find(nums1[i]) != nums1_map.end()) {
            nums1_map[nums1[i]]++;
        } else {
            nums1_map[nums1[i]] = 1;
        }
    }

    for (std::map<int, int>::iterator it = nums1_map.begin(); it != nums1_map.end(); it++) {
        it->second = 1;
    }

    std::map<int, int> nums2_map;
    for (int i = 0;i < nums2.size(); i++) {
        if (nums2_map.find(nums2[i]) != nums2_map.end()) {
            nums2_map[nums2[i]]++;
        } else {
            nums2_map[nums2[i]] = 1;
        }
    }

    for (std::map<int, int>::iterator it = nums2_map.begin(); it != nums2_map.end(); it++) {
        it->second = 1;
    }

    for (std::map<int, int>::iterator it = nums2_map.begin(); it != nums2_map.end(); it++) {
        if (nums1_map.find(it->first) != nums1_map.end()) {
            nums1_map[it->first]++;
        } else {
            nums1_map[it->first] = 1;
        }
    }

    std::vector<int> result;
    for (std::map<int, int>::iterator it = nums1_map.begin(); it != nums1_map.end(); it++) {
        if (it->second > 1) {
            result.push_back(it->first);
        }
    }

    return result;
}

int main() {
    std::vector<int> nums1;
    std::vector<int> nums2;

    std::cout << "输入数组nums1：" << std::endl;
    int temp = 0;
    while (std::cin >> temp && temp != -1) {
        nums1.push_back(temp);
    }

    std::cout << "输入数组nums2：" << std::endl;
    while (std::cin >> temp && temp != -1) {
        nums2.push_back(temp);
    }

    auto result = IntersectionOfTwoArrays(nums1, nums2);
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}