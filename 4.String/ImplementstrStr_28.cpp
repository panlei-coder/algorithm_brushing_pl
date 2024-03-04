#include <iostream>
#include <string>
#include <vector>

// 暴力算法
// int strStr(std::string haystack, std::string needle) {
//     for (int i = 0; i < haystack.size(); i++) {
//         int k = i;
//         int j = 0;
//         for (; j < needle.size(); j++) {
//             if (k < haystack.size() && haystack[k] == needle[j]) {
//                 k++;
//             } else {
//                 break;
//             }
//         }

//         if (j == needle.size()) {
//             return i;
//         }
//     }

//     return -1;
// }

// KMP算法
// 求最长相等前后缀长度
std::vector<int> getNext(std::string needle) {
    std::vector<int> next(needle.size());
    int prefix = 0;
    int sufix = 0;
    next[0] = 0;
    for (sufix = 1; sufix < needle.size(); sufix++) {
        while (prefix > 0 && needle[prefix] != needle[sufix]) {
            /*
            回退，因为这个时候已经知道了前缀prefix之前的和后缀sufix之前的是匹配的，
            所以只需要让前缀prefix之前的已经匹配的部分找到它们的最长相同的前后缀长度，
            就知道了回退之后的位置，new_prefix之前的一定是与后缀sufix之前的是匹配的。
            */ 
            prefix = next[prefix - 1]; 
        }
        if (needle[sufix] == needle[prefix]) {
            prefix++;
        }
        next[sufix] = prefix;
    }

    return next;
}

int strStr(std::string haystack, std::string needle) {
    auto next = getNext(needle);
    int j = 0;
    for (int i = 0; i < haystack.size(); i++) {
        while (haystack[i] != needle[j] && j > 0) { // 这里的思想和getNext函数的回退也是一样的
            j = next[j - 1];
        }

        if (haystack[i] == needle[j]) {
            j++;
        }

        if (j == needle.size()) {
            return i - (j - 1);
        }
    }

    return -1;
}

int main() {

    return 0;
}