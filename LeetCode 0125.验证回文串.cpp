//
// Created by egl1an on 2023/10/14.
//
#include "predefs.h"

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            // skip non-alphanumeric characters
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;

            // convert case and check if characters are the same
            if (tolower(s[left]) != tolower(s[right])) {return false;}
            left++; // pointer continue move
            right--;
        }
        return true; // if we can get here ,it means it is determined to be successful
    }

};