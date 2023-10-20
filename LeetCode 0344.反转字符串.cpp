//
// Created by egl1an on 2023/10/10.
//
#include "predefs.h"

// 对撞指针法
//
class Solution {
public:
    void reverseString(vector<char> &s) {
        int left = 0 , right = s.size() - 1;
        while (left < right){
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;

            left++;
            right--;
        }
    }

};;