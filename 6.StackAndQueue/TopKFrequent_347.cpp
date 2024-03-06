#include <iostream>
#include <unordered_map>
#include <queue>

struct Compare {
    bool operator()(const std::pair<int, int>& first, const std::pair<int, int>& second) {
        return first.second < second.second;
    }
};

std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> nums_map;
    for (int i = 0; i < nums.size(); i++) {
        nums_map[nums[i]]++;
    }

    // 第二个参数为存储元素的容器类，第三个比较器参数为，class Compare
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> pq;
    for (auto it = nums_map.begin(); it != nums_map.end(); it++) {
        pq.push(std::pair<int, int>(it->first, it->second));
    }

    std::vector<int> result;
    for (int i = 0; i < k; i++) {
        auto temp = pq.top();
        result.push_back(temp.first);
        pq.pop();
    }

    return result;
}

int main() {
    std::vector<int> nums;
    int k = 0;
    int temp = 0;
    while (std::cin >> temp && temp != -1) {
        nums.push_back(temp);
    }
    std::cin >> k;

    auto ret = topKFrequent(nums, k);
    for (int i = 0; i < ret.size(); i++ ) {
        std::cout << ret[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}