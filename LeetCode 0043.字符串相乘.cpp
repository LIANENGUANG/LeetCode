
//
// Created by egl1an on 2023/10/21.
//
#include "predefs.h"

class Solution {
public:
    string multiply(string num1, string num2) {
        // 获取两个字符串的长度
        int m = num1.size(), n = num2.size();

        // 创建一个结果数组，长度为m+n。这是因为两个长度分别为m和n的数相乘，
        // 结果的长度最大为m+n。例如，99 * 99 = 9801。
        vector<int> res(m + n, 0);

        // 从num1的最低位开始
        for (int i = m - 1; i >= 0; i--) {
            // 对于num1的每一位，从num2的最低位开始相乘
            for (int j = n - 1; j >= 0; j--) {
                // 将当前位的字符转换为整数并相乘
                int mul = (num1[i] - '0') * (num2[j] - '0');

                // 计算结果应该添加到res中的位置
                // p1是结果的十位，p2是结果的个位
                int p1 = i + j, p2 = i + j + 1;

                // 将乘法的结果与res[p2]中的当前值相加
                int sum = mul + res[p2];

                // 更新res[p2]为新的个位数值
                res[p2] = sum % 10;
                // 将进位的值加到res[p1]
                res[p1] += sum / 10;
            }
        }

        // 将结果数组转换为字符串
        string result;
        for (int num : res) {
            // 如果结果字符串为空，并且当前数字为0，则跳过该数字
            // 否则，将数字添加到结果字符串中
            if (!(result.empty() && num == 0)) {
                result += to_string(num);
            }
        }

        // 如果结果字符串为空，则返回"0"，否则返回结果字符串
        return result.empty() ? "0" : result;
    }
};


//res : 0 0 0 0

1 2
3 4

4 8
3 6

1 0 8