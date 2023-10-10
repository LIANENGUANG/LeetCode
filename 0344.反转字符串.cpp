//
// Created by egl1an on 2023/10/10.
//
#include "predefs.h"

class Solution {
public:
    void reverseString(vector<char> &s) {
        for (int i = 0; i < s.size() / 2; i++) {
            char temp = s[i];
            s[i] = s[s.size() - 1 - i];
            s[s.size() - 1 - i] = temp;
        }
    }
};
;