//
// Created by egl1an on 2023/10/7.
//
#include "predefs.h"

class Solution {
public:
    // 乘的话可能比较大，因此开long long 更加保险一些
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

private:
    stack<int> s;

    int calc(int x, int y, string &token) {
        if (token == "+") return x + y;
        if (token == "-") return x - y;
        if (token == "*") return x * y;
        if (token == "/") return x / y;
        return 0;
    }
};

int main0150 (){
    vector<string> tokens = {"4","13","5","/","+"};
    Solution sol;
    cout << sol.evalRPN(tokens);

}
