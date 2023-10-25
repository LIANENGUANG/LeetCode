//
// Created by egl1an on 2023/10/25.
//
#include "predefs.h"

class Solution {
public:
    int reversePairs(vector<int> &nums) {
        // 从整个数组的范围开始
        return mergeSort(nums, 0, nums.size() - 1);
    }

    // 使用归并排序的方法计算翻转对的数量
    int mergeSort(vector<int> &nums, int low, int high) {
        // 如果当前子数组只有一个元素或者没有元素，则无翻转对
        if (low >= high) return 0;

        // 找到中间位置
        int mid = low + (high - low) / 2;

        // 分别计算左半部分和右半部分的翻转对的数量
        int count = mergeSort(nums, low, mid) + mergeSort(nums, mid + 1, high);

        // 检查条件：左边的数字是否大于右边数字的两倍
        // 注意：这一步的时间复杂度是O(n)，因为j在循环中只会增加，不会减少
        for (int i = low, j = mid + 1; i <= mid; i++) {
            while (j <= high && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += j - (mid + 1);
        }

        // 使用常规的归并排序合并已经排序的半部分
        merge(nums, low, mid, high);
        return count;
    }

    // 归并排序函数
    void merge(vector<int> &nums, int low, int mid, int high) {
        // 确定子数组的大小
        int n1 = mid - low + 1;
        int n2 = high - mid;

        // 创建左半部分和右半部分的临时数组（已经确定大小）
        vector<int> left(n1), right(n2);

        // 以low和mid为基准定位后依次复制原数组数据到临时数组
        for (int i = 0; i < n1; i++) left[i] = nums[low + i];
        for (int i = 0; i < n2; i++) right[i] = nums[mid + 1 + i];

        // 合并两个临时数组
        int i = 0, j = 0, k = low;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                nums[k++] = left[i++];
            } else {
                nums[k++] = right[j++];
            }
        }
        // 复制剩余的元素
        while (i < n1) nums[k++] = left[i++];
        while (j < n2) nums[k++] = right[j++];


    }
};


// 0 1 2 3 4 5
