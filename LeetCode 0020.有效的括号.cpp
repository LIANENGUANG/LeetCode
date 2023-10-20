
//
// Created by egl1an on 2023/10/6.
//
#include "predefs.h"

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char ch: s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                stk.push(ch);
            } else {
                // )（)此时栈直接为空，因为）根本不会入栈
                if (stk.empty()) return false;

                char top = stk.top();
                if (ch == ')' && top != '(')return false;
                if (ch == '}' && top != '{')return false;
                if (ch == ']' && top != '[')return false;

                stk.pop();
            }
        }
        return stk.empty();
        // ((()) -> ( 此时栈不为空，stk.empty 为false仍旧是无效的，因为还有残留的括号

    }
};

int main20() {
    string s = s = "()[])}";
    Solution sol;
    bool result = 0;
    result = sol.isValid(s);
    cout << result;
}