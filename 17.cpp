#include <map>
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) {
            return vector<string> {};
        }
        
        map<char, vector<string>> mappings;
        mappings['2'] = vector<string> {"a", "b", "c"};
        mappings['3'] = vector<string> {"d", "e", "f"};
        mappings['4'] = vector<string> {"g", "h", "i"};
        mappings['5'] = vector<string> {"j", "k", "l"};
        mappings['6'] = vector<string> {"m", "n", "o"};
        mappings['7'] = vector<string> {"p", "q", "r", "s"};
        mappings['8'] = vector<string> {"t", "u", "v"};
        mappings['9'] = vector<string> {"w", "x", "y", "z"};
        vector<string> res = mappings[digits[0]];
        vector<string> tmp;
        
        for (size_t i = 1; i < digits.size(); ++i) {
            vector<string> v = mappings[digits[i]];
            for (auto str : res) {
                for (auto chr : v) {
                    tmp.push_back(str + chr);
                }
            }
            res.swap(tmp);
            tmp.clear();
        }
        return res;
        
    }
};