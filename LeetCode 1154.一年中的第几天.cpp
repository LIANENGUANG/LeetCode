//
// Created by egl1an on 2023/10/24.
//
#include "predefs.h"

class Solution {
public:
    int dayOfYear(string date) {
        // 定义每个月的天数，注意这是非闰年的天数
        int days[12] = {31, 28, 31, 30, 31,
                        30, 31, 31, 30, 31, 30, 31};
        // 提取字符串中的年、月、日
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        // 如果是闰年，二月份天数为 29
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            days[1] = 29;
        }
        // 计算给定日期前的总天数
        // 当月的直接作为初始值，因此循环是不会走到当月
        //month :3  day:6
        // result : 6 + days[0] + days[1]
        int result = day;
        for (int i = 0; i < month - 1; ++i) {
            result += days[i];
        }
        return result;
    }
};

