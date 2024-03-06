#include <iostream>
#include <stack>
#include <vector>
#include <queue>

/* 单调队列 */
class MonotonicQueue {
public:
    MonotonicQueue() = default;

    void pop(int value) {
        if (!monotonic_queue.empty() && value == monotonic_queue.front()) {
            monotonic_queue.pop_front();
        }
    }

    void push(int value) {
        while (!monotonic_queue.empty() && value > monotonic_queue.back()) {
            monotonic_queue.pop_back();
        }
        monotonic_queue.push_back(value);
    }

    int front() {
        return monotonic_queue.front();
    }

private:
    std::deque<int> monotonic_queue;
};

std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
    // 超出时间限制
    // std::vector<int> result(nums.size() - k + 1); 
    // std::queue<int> sliding_window;
    // int max_num = INT32_MIN;
    // for (int i = 0; i < k; i++) {
    //     sliding_window.push(nums[i]);
    //     max_num = std::max(max_num, nums[i]);
    // }
    // result[0] = max_num;

    // for (int i = 1; i < nums.size() - k + 1; i++) {
    //     int front = sliding_window.front();
    //     sliding_window.pop();
    //     if (front == max_num) {
    //         max_num = INT32_MIN;
    //         int size = sliding_window.size();
    //         for (int j = 0; j < size; j++) {
    //             int temp = sliding_window.front();
    //             max_num = std::max(max_num, temp);
    //             sliding_window.pop();
    //             sliding_window.push(temp);
    //         }
    //     }

    //     max_num = std::max(max_num, nums[i + k - 1]);
    //     sliding_window.push(nums[i + k - 1]);
    //     result[i] = max_num;
    // }

    // return result;

    // 使用std::deque实现单调队列来解决问题
    std::vector<int> result(nums.size() - k + 1); 
    MonotonicQueue sliding_window;
    for (int i = 0; i < k; i++) {
        sliding_window.push(nums[i]);
    }
    result[0] = sliding_window.front();

    for (int i = 1; i < nums.size() - k + 1; i++) {
        sliding_window.pop(nums[i - 1]);
        sliding_window.push(nums[i + k - 1]);
        result[i] = sliding_window.front();
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

    auto ret = maxSlidingWindow(nums, k);
    for (int i = 0; i < ret.size(); i++ ) {
        std::cout << ret[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}