//
// Created by egl1an on 2023/10/7.
//
#include "predefs.h"

class solution {
public:
    int calculate(string s) {
        // 数学栈、符号栈
        stack<int> nums, ops;

        int res = 0;
        // 当前的符号，1 代表正， -1 代表负
        int sign = 1;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                int num = 0;
                // 处理数字，数字可能有多位
                while (i < s.size() && isdigit(s[i])) {
                    // 这是一个常用的技巧
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                // 处理完一个完整的数之后将其加入到结果当中
                res += sign * num;
                // 回退一位字符索引，因为for循环还会执行i++
                // 因为在while循环最后一次不成立之前i++了一次，这里加了本身是不成立的
                // 因此要回退到上一次，也就是是数字字符那里，然后再for循环那里往下一个索引前进
                i--;
            } else if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '(') {
                // 遇到左括号，保存当前结果和符号
                nums.push(res);
                ops.push(sign);
                // 重置结果和符号
                res = 0;
                sign = 1;
            } else if (c == ')') {
                // 遇到右括号，计算括号内得的结果
                // 栈顶符号是当前的符号
                res *= ops.top();
                // 移除栈顶符号
                ops.pop();
                // 添加括号前的计算结果
                res += nums.top()
                // 移除已经合并的结果
                nums.pop();
            }
        }
        return res;
    }
};