//
// Created by egl1an on 2023/11/10.
//
#include "predefs.h"

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        // 创建最小堆，使用C++的priority_queue，并使用greater<int> 使其成为最小堆
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // 遍历数组nums
        for (int num: nums) {
            // 将当前元素加入最小栈
            minHeap.push(num);
            // 如果堆的大小超过了 k，也就是说堆中已经有 k+1 个元素
            // 那么我们就移除堆顶元素，也就是最小的元素
            // 这样，堆中始终保持了最大的 k 个元素
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        // 遍历完所有元素后，堆中的元素就是数组中最大的 k 个元素
        // 且由于这是最小堆，堆顶元素就是这 k 个元素中最小的，也就是数组中第 k 大的元素
        return minHeap.top();
    }
};