//
// Created by egl1an on 2023/11/10.
//
#include "predefs.h"

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
    // 创建一个最大堆，并把所有的石头的重量放入堆中
    priority_queue<int> heap(stones.begin(),stones.end());

    // 当堆中的石头数量大于 1 时，持续操作
    while(heap.size() > 1){
        // 取出重量最大的石头 y
        int y = heap.top();
        heap.pop();

        // 取出重量第二大的石头 x
        int x = heap.top();
        heap.pop();

        // 如果两块石头的重量不相等，那么将新的石头（y - x）放回到堆中
        if(x != y){
            heap.push(y - x);
        }
    }
    // 如果堆不为空，返回栈顶元素，否则返回 0
    return heap.empty() ? 0 :heap.top();
    }
};