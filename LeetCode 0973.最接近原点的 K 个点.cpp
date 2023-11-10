//
// Created by egl1an on 2023/11/10.
//
# include "predefs.h"

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        // 定义一个比较函数，用于构建最大堆。这个函数将根据点到原点的距离来比较两个点。根据这个函数把距离最大的点放在堆顶
        auto comp = [](const pair<vector<int>, double> &a, const pair<vector<int>, double> &b) {
            return a.second < b.second;
        };

        // 使用定义的比较函数，构建一个最大堆。
        priority_queue<pair<vector<int>, double>, vector<pair<vector<int>, double>>, decltype(comp)> pq(comp);

        // 遍历所有的点
        for (const auto &point: points) {
            double distance = sqrt(point[0] * point[0] + point[1] * point[1]);
            // 将当前点和其距离作为一个 pair添加到堆中
            pq.emplace(point, distance);
            // 如果堆的大小超过k，就删除对顶元素，也就是删除距离最大的点
            if (pq.size() > k) {
                pq.pop();
            }
        }
        // 创建一个结果列表
        vector<vector<int>> result;
        // 将堆中的所有点添加到结果列表中
        while (!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }

        // 返回结果列表
        return result;
    }
};