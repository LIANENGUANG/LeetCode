//
// Created by egl1an on 2023/10/25.
//
#include "predefs.h"

class MountainArray {
public:
    int get(int index);

    int length();
};

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int left = 0, right = mountainArr.length() - 1;
        // 寻找山脉的峰顶索引
        while (left < right) {
            // 定义中间点
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int peak = left;

        // 在峰顶的左侧升序部分查找目标值
        left = 0;
        right = peak;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midVal = mountainArr.get(mid);
            // 如果恰好是山顶
            if (midVal == target) return mid;
                // 如果目标值大于当前中间点，说明目标点在midVal的右侧
                // 则应该在左侧升序部分区间的右半部分
            else if (midVal < target) left = mid + 1;
                // 如果他既不是山顶又不是在右半部分，则在左半部分
            else right = mid - 1;
        }

        // 在峰顶右侧降序部分查找目标值，和左侧的同理，注意区分上升还是下降的顺序
        left = peak;
        right = mountainArr.length() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midVal = mountainArr.get(mid);
            if (midVal == target) return mid;
            else if (midVal < target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
};
