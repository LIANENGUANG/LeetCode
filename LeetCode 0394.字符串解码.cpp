//
// Created by egl1an on 2023/11/6.
//
#include "predefs.h"

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString;
        int k = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                k = k * 10 + (ch - '0');  // 构建数字
            } else if (ch == '[') {
                // 把当前的数字和字符串分别压入栈中
                countStack.push(k);
                stringStack.push(currentString);
                // 重置当前的数字和字符串
                currentString = "";
                k = 0;
            } else if (ch == ']') {
                // 弹出一个数字，表示重复次数
                int repeatTimes = countStack.top();
                countStack.pop();
                // 构建字符串
                string decodedString = stringStack.top();
                stringStack.pop();
                for (int i = 0; i < repeatTimes; ++i) {
                    decodedString += currentString;
                }
                // 更新当前字符串为解码后的字符串
                currentString = decodedString;
            } else {
                // 如果是字母，添加到当前字符串
                currentString += ch;
            }
        }
        return currentString;
    }
};
