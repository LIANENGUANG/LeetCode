//
// Created by egl1an on 2023/10/18.
//
#include "predefs.h"

class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        int len = flowerbed.size();
        // 遍历查空，判断两侧位置当前情况下是否满足要求
        // 条件：1.有地 2.有花
        for (int i = 0; i < len && n > 0; ++i) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == len - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;
                n--;
            }
        }
        return n <= 0;
    }
};