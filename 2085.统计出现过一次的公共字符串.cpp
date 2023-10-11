//
// Created by egl1an on 2023/10/11.
//

//您可以将每个字符的ASCII值转换为整数并对这些值进行异或操作。但有几个问题需要注意：
//长度问题: 如果两个字符串长度不同，你无法直接进行异或操作，因为你没有对应的字符进行异或操作。
//可逆性问题: 由于异或操作是可逆的，不同的字符串可以产生相同的异或结果。例如，字符串"ab"和字符串"ba"将产生相同的异或值，即使它们是不同的字符串。
//大数问题: 如果字符串非常长，它的异或值可能会超过标准整数的范围，这可能导致溢出。
#include "predefs.h"
class Solution {
public:
    int countWords(vector<string> &words1, vector<string> &words2) {
        map<string, int> stringTonumber01;
        map<string, int> stringTonumber02;
        vector<string> result;
        for (auto &word: words1) {
            stringTonumber01[word]++;
        }
        for (auto &word: words2) {
            stringTonumber02[word]++;
        }
        int unique = 0;
        for (auto &[word, count]: stringTonumber01) {
            if (count == 1 && stringTonumber02[word] == 1) {
                unique++;
            }
        }
        return unique;
    }
};