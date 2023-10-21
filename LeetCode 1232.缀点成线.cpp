//
// Created by egl1an on 2023/10/21.
//
#include "predefs.h"

class Solution {
public:
    bool checkStraightLine(vector<vector<int>> &coordinates) {
        int n = coordinates.size();
        if (n <= 2) return true;// 两个点总能连接一条直线；
        // 初始化第一个点，第一个点事coordinates[0]
        // 其横纵坐标分别是coordinates[0][0]和coordinates[0][1]
        int x1 = coordinates[0][0], y1 = coordinates[0][1];
        // 初始化第二个点，第一个点事coordinates[1]
        // 其横纵坐标分别是coordinates[1][0]和coordinates[1][1]
        int x2 = coordinates[1][0], y2 = coordinates[1][1];

        for (int i = 2; i < n; ++i) {
            int x3 = coordinates[i][0], y3 = coordinates[i][1];
            // 利用交叉乘积的技巧
            if ((y2 - y1) * (x3 - x2) != (y3 - y2) * (x2 - x1)) {
                return false;
            }
        }
        return true;
    }
};