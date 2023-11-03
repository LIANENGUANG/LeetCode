//
// Created by egl1an on 2023/11/2.
//
#include "predefs.h"
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // 创建一个未排序的map，键是整数，值也是整数
        unordered_map<int, int> map;
        // 将0的出现次数初始化为
        map[0] = 1;
        // 初始化累加和和计数器
        int sum = 0, count = 0;
        // 遍历输入的整数向量
        for (int i = 0; i < nums.size(); i++) {
            // 计算累加和
            sum += nums[i];
            // 如果累加和减去k的结果在map中存在
            if (map.count(sum - k)) {
                // 那么就找到了一个和为k的子数组，所以将计数器加上map中对应的值（也就是等于sum - k的子数组当前的个数）
                count += map[sum - k];
            }
            // 将累加和的出现次数加一
            map[sum]++;
        }
        return count; // 返回计数器
    }
};