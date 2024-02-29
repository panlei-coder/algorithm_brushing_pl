#include <iostream>
#include <string>
#include <map>

bool ValidAlphabets(std::string s, std::string t) {
    std::map<char, int> s_map;
    std::map<char, int> t_map;

    for (int i = 0; i < s.length(); i++) {
        if (s_map.find(s[i]) != s_map.end()) {
            s_map[s[i]]++;
        } else {
            s_map[s[i]] = 1;
        }
    }

    for (int i = 0; i < t.length(); i++) {
        if (t_map.find(t[i]) != t_map.end()) {
            t_map[t[i]]++;
        } else {
            t_map[t[i]] = 1;
        }
    }

    if (s_map.size() != t_map.size()) {
        return false;
    } 

    for (int i = 0; i < s.length(); i++) {
        if (s_map[s[i]] != t_map[s[i]]) {
            return false;
        }
    }

    return true;
}

int main() {
    std::string s;
    std::string t;

    std::cout << "输入字符串s：" << std::endl;
    std::cin >> s;
    std::cout << "输入字符串t：" << std::endl;
    std::cin >> t;

    auto result = ValidAlphabets(s, t);
    std::cout << result << std::endl;

    return 0;
}