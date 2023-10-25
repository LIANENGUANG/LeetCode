//
// Created by egl1an on 2023/10/25.
//
#include "predefs.h"

class Solution {
public:
    int peakIndexInMountainArray(vector<int> &arr) {
        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {
            // 查找中间点
            int mid = left + (right - left) / 2;

            // 如果当前元素小于它右侧的元素，说明封顶在右边
            // 同时直接到mid + 1，因为arr[mid] < arr[mid + 1]
            // 因此峰顶不可能是当前mid索引所对应的值
            if (arr[mid] < arr[mid + 1]) {
                left = mid + 1;
            }
            // 否则，峰顶在左边或就是当前的中间元素
            else {
                right = mid;
            }
        }
        return left; // 返回峰顶索引
    }
};