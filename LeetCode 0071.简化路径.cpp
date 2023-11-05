//
// Created by egl1an on 2023/11/6.
//
#include "predefs.h"

class Solution {
public:
    string simplifyPath(string path) {
        // 使用vector 模拟栈
        vector<string> dirs;
        string cur;
        // 使用stringstream 方便按'/'切割
        stringstream ss(path);
        // 按'/'切割路径
        while (getline(ss, cur, '/')) {
            if (cur == "..") {
                // 如果非空也就是说不是根目录，则返回上一级目录
                if (!dirs.empty()) dirs.pop_back();
            } else if (!cur.empty() && cur != ".") {
                // 添加目录到路径中
                dirs.push_back(cur);
            }
        }
        string result = "/";
        for (int i = 0; i < dirs.size(); ++i) {
            result += dirs[i];
            // 除了最后一个目录，每个目录后面都要加"/"
            if (i < dirs.size() - 1) {
                result += "/";
            }
        }
        return result;
    }
};