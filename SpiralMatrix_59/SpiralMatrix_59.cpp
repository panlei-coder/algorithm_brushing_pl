#include <iostream>
#include <vector>

std::vector<std::vector<int>> GenrateSpiralMatrix(int n) {
    std::vector<std::vector<int>> matrix;
    for (int index = 0; index < n; index++) {
        std::vector<int> temp(n);
        matrix.push_back(std::move(temp));
    }

    int i = 0;
    int j = 0;
    int value = 1;
    int count = 0;
    for (int step = n; step > 0;) {
        count = 0;
        while (count < step - 1) {
            matrix[i][j] = value;
            value++;
            j++;
            count++;
        }

        count = 0;
        while (count < step - 1) {
            matrix[i][j] = value;
            value++;
            i++;
            count++;
        }

        count = 0;
        while (count < step - 1) {
            matrix[i][j] = value;
            value++;
            j--;
            count++;
        }

        count = 0;
        while (count < step - 1) {
            matrix[i][j] = value;
            value++;
            i--;
            count++;
        }

        i++;
        j++;
        step -= 2;
    }

    if (n % 2 != 0) {
        int index = n / 2;
        matrix[index][index] = n * n;
    }

    return matrix;
}

int main() {
    int n = 0;

    std::cout << "输入整数n：" << std::endl;
    std::cin >> n;

    auto result = GenrateSpiralMatrix(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}