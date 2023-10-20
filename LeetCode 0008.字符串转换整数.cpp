//
// Created by egl1an on 2023/10/2.
//
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long long result = 0;

        // 1.跳过所有空格
        while (i < s.size() && s[i] == ' ')
            i++;

        // 2.检查是否有符号位
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            // 判断完符号位往前走一个字符
            i++;
        }
        // 3.转换字符为数字并且避免溢出；利用字符的大小关系，isdigit判断是数字字符然后利用减去'0'字符得到他的具体数字（通过两个字符间的距离）
        while (i < s.size() && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            if (sign == 1 && result > INT_MAX) return INT_MAX;
            // 这里注意符号，result 本身不带有符号
            if (sign == -1 && (-1 * result) < INT_MIN) return INT_MIN;
            i++;
        }
        return result * sign;
    }
};

int main08() {
    Solution sol;
    cout << sol.myAtoi("42") << endl;           // Expected: 42
    cout << sol.myAtoi("   -42") << endl;       // Expected: -42
    cout << sol.myAtoi("4193 with words") << endl; // Expected: 4193
    cout << sol.myAtoi("words and 987") << endl;  // Expected: 0
    cout << sol.myAtoi("-91283472332") << endl;   // Expected: -2147483648
    return 0;
}