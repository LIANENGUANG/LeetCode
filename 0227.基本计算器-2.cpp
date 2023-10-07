//
// Created by egl1an on 2023/10/7.
//
// 将中缀表达式转为 150 题的（后缀表达式）逆波兰式在求解
#include "predefs.h"

class Solution {
public:
    long long calculate(string s) {
        // 保证以数字结尾时，那个数字能够正确被放到数组当中，因为下面对数字放到tokens当中时条件是当前不是一个数字字符才push_back进去
        s += ' ';
        // 用于放入数字的字符串数组，用于存放整个后缀表达式
        vector<string> tokens;
        // 临时提取和保存数字
        string number = "";
        for (char ch: s) {
            // 说明某字符是一个数字字符利用ascll码的关系
            if (ch >= '0' && ch <= '9') {
                // 字符链接比较 12，,12 是一个数，但是由于是一个一个字符读入的，因此要进行一个字符的拼接
                number += ch;
                // 确实是一个数字则直接拼接该数字跳过此轮循环，不会调到下面的运算符相关的操作
                continue;
                // 如果不是一个数字，则将之前存储的数字放到数组当中去
            } else {
                if (!number.empty()) {
                    // 将此数字拼接好的一个数字放到tokens 当中
                    tokens.push_back(number);
                    // 清空存储字符的number并且进行下一次字符的存储
                    number = "";
                }
            }
            // 进行完一次上述的if-else后进去下面运算符的操作
            if (ch == ' ') continue;
            // 得到运算符的优先级当前这个ch的
            int currRank = getRank(ch);
            // 如果当前运算符栈顶的运算符优先级大于或者等于当前取到的运算符的优先级，依次比较
            while (!ops.empty() && getRank(ops.top()) >= currRank) {
                // 注意此时的ops栈内都是char 而 tokens数组是string 类型
/*
// 使用 to_string(ops.top()) 会有问题，
因为 std::to_string 并不是为单个字符设计的，而是为数字（例如 int, long, float, double 等）设计的。
*/
                tokens.push_back(string(1, ops.top())); // 构造了包含一个字符的字符串
                ops.pop();
            }
            // 将那些比当前运算符优先级高的字符均放到表达式当中之后，将当前运算符入栈
            ops.push(ch);
        }
        // 当所有的字符都处理完后，将运算符栈出栈放到后缀表达式当中
        while (!ops.empty()) {
            tokens.push_back(string(1, ops.top()));
            ops.pop();
        }
        return evalRPN(tokens);
    }

private:
    // 运算符栈
    stack<char> ops;

    int getRank(char ch) {
        if (ch == '+' || ch == '-') return 1;
        if (ch == '*' || ch == '/') return 2;
        return 0;

    }

    long long evalRPN(vector<string> &tokens) {
        for (string &token: tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int y = s.top();
                // 有符号直接出栈
                s.pop();
                int x = s.top();
                s.pop();
                int z = calc(x, y, token);
                s.push(z);
            } else {
                // 字符转数字，因为此时的token不是符号而是一个数字字符
                s.push(atoi(token.c_str()));
            }
        }
        // 最终必然只剩一个数-表达式总是有效的情况下
        return s.top();
    }

    stack<int> s;

    int calc(int x, int y, string &token) {
        if (token == "+") return x + y;
        if (token == "-") return x - y;
        if (token == "*") return x * y;
        if (token == "/") return x / y;
        return 0;
    }
};

int main() {
    string s = "3+2*2";
    Solution sol;
    cout << sol.calculate(s);
}