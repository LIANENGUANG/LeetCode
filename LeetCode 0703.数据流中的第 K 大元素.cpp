//
// Created by egl1an on 2023/11/10.
//
#include "predefs.h"

class KthLargest {
public:
    // 定义一个优先队列（最小堆），堆中元素个数不超过k，堆顶元素是当前第k大的数
    priority_queue<int, vector<int>, greater<int>> q;
    // 记录堆的大小（即第k大的数）
    int size;

    KthLargest(int k, vector<int> &nums) {
        // 设置堆的大小为k
        size = k;
        // 遍历输入数组，将每个元素插入堆中
        for (int num: nums) {
            add(num);
        }
    }

    // 添加元素到堆中的方法
    int add(int val) {
        // 如果堆的元素个数小于k，直接将新元素添加到堆中
        if (q.size() < size) {
            q.push(val);
        }
        // 如果新元素大于堆顶元素（即新元素比当前第k大的数还要大）
        else if (val > q.top()) {
            // 删除堆顶元素
            q.pop();
            // 将新元素添加到堆中
            q.push(val);
        }
        // 返回堆顶元素，即当前第k大的数
        return q.top();
    }
};