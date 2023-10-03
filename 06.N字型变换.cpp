#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        //std::vector<std::string> rows：声明了一个字符串向量名为 rows。
        //min(numRows,int(s.size()))：这是一个函数调用，用于确定向量 rows 的大小。它的意思是取 numRows 和 s.size() 之间的较小值。
        //为什么要这样做？考虑这样一个情况：如果 s 的长度小于 numRows，那么 Z 字形的行数实际上就是 s 的长度，因为不可能有空的行。
        //例如：
        //假设输入字符串为 "ABC"，行数为 5。实际上，Z 字形只需要 3 行，因为字符串长度只有 3，所以不存在第4行和第5行。
        //因此，这一行代码确保了 rows 向量的大小与实际需要的行数相匹配，而不是 blindly 根据 numRows 来确定。
        vector<string> rows(min(numRows, int(s.size())));

        int curRow = 0;
        bool goingDown = false;

        for (char c: s) {
            rows[curRow] += c;
            // 判断是否到了转向的位置，在上下边界需要进行转向的操作，开始时默认向下移动
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }
        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
};

int main06(){
    string s = "PAYPALISHIRING";
    Solution sol;
    cout << sol.convert(s,4) << endl;
}