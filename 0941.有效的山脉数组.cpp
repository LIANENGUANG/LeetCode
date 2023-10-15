//
// Created by egl1an on 2023/10/15.
//
#include "predefs.h"

class Solution {
public:
    bool validMountainArray(vector<int> &arr) {
        // 标记前半段 - 0 还是后半段 - 1
        // 一个元素的情况
        if (arr.size() == 1) return false;
        // 边界条件判断，防止完全上升的情况
            if (arr[1] <= arr[0] || arr[arr.size() - 1] >= arr[arr.size() - 2]) return false;
        int flag = 0;
        for (int i = 1; i < arr.size(); i++) {
            // 开始时均上升，直到下降点时跳出
            // 防止出现等号的情况
            if (arr[i] == arr[i - 1]) return false;
            if (flag == 0 && arr[i] > arr[i - 1]) continue;
            else {
                flag = 1;
                if (arr[i] > arr[i - 1]) return false;
            }

        }
        return true;

    }
};