#include "predefs.h"


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 创建一个最小堆
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // 将两个数组的所有元素都放入堆中
        for (int num : nums1) {
            minHeap.push(num);
        }
        for (int num : nums2) {
            minHeap.push(num);
        }

        // 弹出堆顶元素直到找到中位数
        int size = nums1.size() + nums2.size();
        int median1 = 0, median2 = 0;
        for (int i = 0; i <= size / 2; i++) {
            if (i == size / 2 - 1) {
                median1 = minHeap.top();
            }
            if (i == size / 2) {
                median2 = minHeap.top();
            }
            minHeap.pop();
        }

        // 如果总元素数量是奇数，则中位数是堆顶元素
        // 如果总元素数量是偶数，则中位数是最后两个弹出的元素的平均值
        return (size % 2 == 0) ? (median1 + median2) / 2.0 : median2;
    }
};