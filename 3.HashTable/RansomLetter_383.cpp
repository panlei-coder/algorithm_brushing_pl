#include <iostream>
#include <unordered_map>
#include <string>

bool canConstruct(std::string ransomNote, std::string magazine) {
    std::unordered_map<char, int> magazine_map;
    for (int i = 0; i < magazine.size(); i++) {
        magazine_map[magazine[i]]++;
    }

    for (int i = 0; i < ransomNote.size(); i++) {
        auto it = magazine_map.find(ransomNote[i]);
        if (it != magazine_map.end()) {
            it->second--;
            if (it->second < 0) {
                return false;
            }
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    
    return 0;
}