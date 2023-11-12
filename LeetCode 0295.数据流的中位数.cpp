//
// Created by egl1an on 2023/11/12.
//
#include "predefs.h"

class MedianFinder {
public:
    priority_queue<int> lo; // 最大堆
    priority_queue<int, vector<int>, greater<int>> hi; // 最小堆
    // 构造函数
    MedianFinder() {
    }

    void addNum(int num) {
        lo.push(num); // 将此数加入到最大堆
        hi.push(lo.top()); // 将最大堆的对顶元素加到最小堆当中
        lo.pop();
        // 维护堆大小，以便最终确定中位数
        if(lo.size() < hi.size()){
            lo.push(hi.top());
            hi.pop();
        }

    }
    // lo的大小一定是大于或者等于hi，因为小于的那种情况再addNum中一定会被处理
    // 如果lo的大小等于hi，取二者中位数，否则一定在 lo 当中
    double findMedian() {
        return lo.size() > hi.size() ? (double) lo.top() : (lo.top() + hi.top()) * 0.5;
    }
};