#include <iostream>
#include <map>

bool isHappy(int n) {
    std::map<int, int> result_map;
    int num = 0;
    int sum = 0;
    while (true) {
        sum = 0;
        while (n > 0) {
            num = n - (n / 10) * 10;
            n = n / 10;
            sum += num * num;
        }

        if (sum == 1) {
            return true;
        }

        if (result_map.find(sum) != result_map.end()) {
            return false;
        } else {
            result_map[sum] = 1;
        }
        
        n = sum;
    }
}

int main() {
    int n = 0;

    std::cout << "输入整数n：" << std::endl;
    std::cin >> n;

    auto ret = isHappy(n); 
    std::cout << ret << std::endl;

    return 0;
}