//
// Created by egl1an on 2023/10/25.
//
#include "predefs.h"

class Solution {
public:
    int findKthPositive(vector<int> &arr, int k) {
        int left = 0, right = arr.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            // 注意这个正整数数组是从 1 开始的严格升序排序数组[1,2,3,4,5,6,7...]
            // 假如我们从这个[1,2,3,4,5,6,7...]找k值，我们会怎么做？
            // 现在数组索引index和数组的value有明显的对应关系:arr[i] = i + 1
            // 正常arr[mid] - mid - 1 = 0，而此时发生了这个式子不为 0
            // 原因就在于在他之前缺少了原有的元素，导致较大的arr[mid]占了原来的位置
            // arr[mid] - mid - 1 等于多少则说明少了几个元素
            // 如果少的不够那么说明还没到第k个缺失元素
            if (arr[mid] - mid - 1 < k) {
                // 没有缺够说明还应该继续提升左边界
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left + k;
    }
};