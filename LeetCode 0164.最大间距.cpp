//
// Created by egl1an on 2023/10/25.
//
#include "predefs.h"

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        // 当数组的元素小于2时，直接返回0
        if(n < 2) return 0;

        // 获取数组的最大值和最小值
        int maxNum = *max_element(nums.begin(), nums.end());
        int minNum = *min_element(nums.begin(), nums.end());

        // 计算桶的大小和数量
        int bucketSize = max(1, (maxNum - minNum) / (n - 1));
        int bucketCount = (maxNum - minNum) / bucketSize + 1;
        // 初始化桶，每个桶存储两个值，即桶内的最小值和最大值
        vector<pair<int, int>> buckets(bucketCount, {-1, -1});

        // 将数字分配到桶中
        for(int num : nums) {
            int index = (num - minNum) / bucketSize;
            if(buckets[index].first == -1) {  // 如果桶是空的
                buckets[index].first = buckets[index].second = num;
            } else {
                buckets[index].first = min(buckets[index].first, num);
                buckets[index].second = max(buckets[index].second, num);
            }
        }

        // 计算最大间距
        int maxGap = 0;
        int prevBucketMax = minNum;
        for(auto &bucket : buckets) {
            if(bucket.first == -1) continue;  // 跳过空桶
            maxGap = max(maxGap, bucket.first - prevBucketMax);
            prevBucketMax = bucket.second;
        }

        return maxGap;
    }
};
