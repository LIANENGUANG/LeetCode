//
// Created by egl1an on 2023/11/6.
//
#include "predefs.h"

class Solution {
public:
    int calculate(string s) {
        int length = s.length();
        // 如果字符串为空，则直接返回0
        if (length == 0) return 0;
        // 使用栈来处理中间结果
        stack<int> stack;
        // 当前解析的数字
        int currentNumber = 0;
        // 上一个操作符，默认为加号
        char operation = '+';
        // 遍历字符串中的每个字符
        for (int i = 0; i < length; i++) {
            char currentChar = s[i];
            // 如果当前字符是数字，则更新currentNumber
            if (isdigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            // 如果当前字符是操作符或到达字符串末尾
            if (!isdigit(currentChar) && !isspace(currentChar) || i == length - 1) {
                // 根据operation变量进行相应操作，注意这里的operation实际上是前一个操作符
                // 而currentChar里存放的才是当前的操作符
                if (operation == '-') {
                    // 如果是减号，将负的currentNumber压入栈
                    stack.push(-currentNumber);
                } else if (operation == '+') {
                    // 如果是加号，直接将currentNumber压入栈
                    stack.push(currentNumber);
                } else if (operation == '*') {
                    // 如果是乘号，将栈顶元素与currentNumber相乘后压入栈
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop * currentNumber);
                } else if (operation == '/') {
                    // 如果是除号，将栈顶元素除以currentNumber后压入栈
                    int stackTop = stack.top();
                    stack.pop();
                    stack.push(stackTop / currentNumber);
                }
                // 更新operation为当前操作符，重置currentNumber
                operation = currentChar;
                currentNumber = 0;
            }
        }
        // 计算栈中所有数的和
        int result = 0;
        while (!stack.empty()) {
            result += stack.top();
            stack.pop();
        }
        // 返回计算结果
        return result;
    }
};
