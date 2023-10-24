//
// Created by egl1an on 2023/10/4.
//
#include "predefs.h"

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        // 初始化两个指针，分别指向两个数组的末尾
        int p1 = m - 1, p2 = n - 1;
        // 设置一个指针，指向nums1的末尾
        int p = m + n - 1;

        // 当两个数组都有元素时进行比较
        while ((p1 >= 0) && (p2 >= 0)) {
            // 比较nums1 和 nums2的元素，并将较大的元素放到nums1的尾部
            // 注意本身是有序的
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            // 移动确认指针p
            p--;
        }
        // 虽然nums1.size() > nums2.size()，但是其中有些都是 0，可以称其为有效位
        // 当有效位比完之后
        // 如果nums2 中还有元素，则应将其全部复制到nums1中；
        while (p2 >= 0) {
            nums1[p] = nums2[p2];
            p--;
            p2--;
        }

    }
};