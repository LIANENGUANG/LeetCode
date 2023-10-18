//
// Created by egl1an on 2023/10/18.
//
#include "predefs.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        // 利用字符串哈希表这个技巧即可完成
        unordered_set<string> seen;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char number = board[i][j];
                if (number != '.') {
                    // 使用字符串流构造行、列和块的字符串
                    // 构造的形如 number in row i
                    // 构造的形如 number in col i
                    // 构造的形如 number in box i/3 - j/3 (对于 0 1 2行和列来说其块索引为 0 - 0，相当于 3 行为1行，3 列为 1 列)
                    // 如果有出现相同的"number in row i" == "number in row i"（列块同理）,find返回不为seen.end()
                    // 条件为真说明有重复，此时直接返回false
                    string row = to_string(number) + " in row " + to_string(i);
                    string col = to_string(number) + " in col " + to_string(j);
                    string box = to_string(number) + " in box " + to_string(i / 3) + "-" + to_string(j / 3);
                    if (seen.find(row) != seen.end() || seen.find(col) != seen.end() || seen.find(box) != seen.end())
                        return false;

                    seen.insert(row);
                    seen.insert(col);
                    seen.insert(box);
                }
            }
        }
        return true;
    }
};