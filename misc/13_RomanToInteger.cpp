#include <string.h>

class Solution {
public:
    int romanToInt(std::string s) {
        int values[131];
        values['I'] = 1;
        values['V'] = 5;
        values['X'] = 10;
        values['L'] = 50;
        values['C'] = 100;
        values['D'] = 500;
        values['M'] = 1000;
        int total = values[s[s.length()-1]];
        for (int i = 0; i < s.length() - 1; i++) {
            if (values[s[i]] < values[s[i+1]]) {
                total -= values[s[i]];
            } else {
                total += values[s[i]];
            }
        }
        return total;
    }
};
