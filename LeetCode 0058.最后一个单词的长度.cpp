#include "predefs.h"

class Solution {
public:
    int lengthOfLastWord(string s) {
        int fast = s.size() - 1; //设置快指针在字符串尾部
        int slow = -1; // 初始化慢指针

        // 跳过尾部的空格
        while(fast >= 0 && s[fast] == ' '){
            fast--;
        }

        // 设置慢指针在最后一个单词的开始位置
        slow = fast;
        while(slow >= 0 && s[slow]!= ' '){
            slow--;
        }
        return fast - slow;
    }
};