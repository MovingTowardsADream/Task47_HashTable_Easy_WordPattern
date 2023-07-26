#include <iostream>
#include <sstream>
#include <vector>
#include <map>

class Solution {
public:
    static bool wordPattern(std::string pattern, std::string s) {
        std::stringstream ss(s);
        std::string word;
        std::map<std::string, char> alphabet;
        std::vector<char> tmp;
        for (int i = 0;i < pattern.size();i++) {
            if (!(ss >> word))
                return 0;
            if (!(alphabet[word])) {
                if (std::find(tmp.begin(), tmp.end(), pattern[i]) != tmp.end())
                    return 0;
                alphabet[word] = pattern[i];
                tmp.push_back(pattern[i]);
            }
            else if (alphabet[word] != pattern[i]) {
                return 0;
            }
        }
        if (ss >> word) {
            return 0;
        }
        return 1;
    }
};


int main() {
    std::cout << Solution::wordPattern("abb", "dog cat");
}