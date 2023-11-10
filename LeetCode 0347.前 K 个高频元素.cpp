//
// Created by egl1an on 2023/11/10.
//
#include "predefs.h"

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts; // 哈希表用来存储每个元素出现的频率
        for (int num : nums) {
            ++counts[num]; // 对每个元素进行计数
        }

        // 创建一个小顶堆，堆中的元素是一个pair，第一个元素是频率，第二个元素是对应的数值
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto& it : counts) {
            // 如果堆的大小已经等于k，那么我们需要检查当前元素的频率是否大于堆顶元素的频率
            if (pq.size() == k) {
                if (it.second > pq.top().first) {
                    pq.pop(); // 如果当前元素的频率大于堆顶元素的频率，那么我们将堆顶元素弹出
                    pq.emplace(it.second, it.first); // 然后将当前元素插入堆中
                }
            } else {
                // 如果堆的大小小于k，那么我们可以直接将当前元素插入堆中
                pq.emplace(it.second, it.first);
            }
        }

        vector<int> ret; // 答案数组
        while (!pq.empty()) {
            ret.push_back(pq.top().second); // 将堆顶元素插入答案数组
            pq.pop(); // 将堆顶元素弹出
        }
        return ret; // 返回答案数组
    }
};