//
// Created by egl1an on 2023/11/2.
//
#include "predefs.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        // 创建一个未排序的 map，键是字符串，值是字符串向量
        unordered_map<string, vector<string>> map;
        // 遍历输入的字符串向量
        for (string &str: strs) {
            // 将当前字符串作为键
            string key = str;
            // 排序键，这样所有的字母异位词都将具有相同的键
            sort(key.begin(), key.end());
            // 在对应的键值对中添加当前字符串
            // str还是str，但是key正好是排过序的
            map[key].push_back(str);
        }
        // 创建一个二维向量来存储结果
        vector<vector<string>> ans;
        // 遍历map
        for (auto & p :map){
            // 将每个键对应的字母异位词组添加到结果中
            ans.push_back(p.second);

        }
        // 返回结果
        return ans;
    }
};