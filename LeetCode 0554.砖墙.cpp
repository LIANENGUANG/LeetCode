//
// Created by egl1an on 2023/11/1.
//
#include "predefs.h"
class Solution
{
public:
    int leastBricks(vector<vector<int>> &wall){
        unordered_map<int, int> gapCounts;// <缝隙索引，出现次数>
        int maxGap = 0;

        for (auto &row : wall)
        {   // 每次进入循环重置sum，因为要计算当前行的缝隙索引值。每次都是从 0 开始叠加
            int sum = 0;
            // 注意：小于row.size() -1为了避免计算最后一块砖的缝隙
            for (int i = 0; i < row.size() - 1; i++){
                sum += row[i];
                // 每次对应的缝隙出现次数++
                gapCounts[sum]++;
                maxGap = max(maxGap,gapCounts[sum]);
            }
        }
        return wall.size() - maxGap;
    }
};