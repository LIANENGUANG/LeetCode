//
// Created by egl1an on 2023/11/2.
//
#include "predefs.h"

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // 创建两个哈希表，一个用于存储字符到单词的映射，另一个用于存储单词到字符的映射
        unordered_map<char, string> char2word;
        unordered_map<string, char> word2char;

        // 分割字符串 s，获取单词列表
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }

        // 检查模式长度和单词列表长度是否相同
        if (pattern.size() != words.size()) {
            return false;
        }

        // 遍历模式中的每个字符
        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];

            // 检查当前字符是否已经与一个单词建立了映射，如果已经建立，检查映射是否正确
            if (char2word.count(c) && char2word[c] != words[i]) {
                return false;
            }

            // 检查当前单词是否已经与一个字符建立了映射，如果已经建立，检查映射是否正确
            if (word2char.count(words[i]) && word2char[words[i]] != c) {
                return false;
            }

            // 建立映射
            char2word[c] = words[i];
            word2char[words[i]] = c;
        }

        // 所有的映射都正确，返回 true
        return true;
    }
};