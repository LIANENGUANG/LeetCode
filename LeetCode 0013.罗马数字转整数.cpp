//
// Created by egl1an on 2023/10/20.
//
#include "predefs.h"

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> roman_map = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
        };
        int result = 0;
        for(int i = 0 ; i < s.size(); i++){
            if(i + 1 < s.size()&& roman_map[s[i]] < roman_map[s[i+1]]){
                result -= roman_map[s[i]];
            }else{
                result += roman_map[s[i]];
            }

    }return result;
}

};