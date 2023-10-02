#include <stdio.h>
#include <iostream>

using namespace std;

//如果输入的字符串s是空的，直接返回空字符串。
//初始化两个变量 start 和 end 来记录最长回文子串的开始和结束位置。
//对于字符串中的每一个字符位置 i，我们尝试将其作为回文子串的中心。
//使用 expandAroundCenter 函数检查以当前字符为中心的奇数长度的回文（例如 "aba"）和偶数长度的回文（例如 "abba"）。
//更新最长回文子串的开始和结束位置。
//返回最长回文子串。
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }

        int start = 0;
        int end = 0;

        for (int i = 0; i < s.length(); i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);

            int len = max(len1, len2);
//条件判断 if (len > end - start):
//len 是当前找到的回文子串的长度。end - start 是之前找到的最长回文子串的长度。
//如果当前找到的回文子串比之前找到的还要长，我们就需要更新start 和 end。
//计算 start 的位置:i 是当前回文子串的中心位置。
//对于奇数长度的回文子串，例如 "aba"，中心是 'b'。对于偶数长度的回文子串，例如 "abba"，中心在 'a' 和 'b' 之间。
//如果回文子串的长度是 len，左半部分的长度是 (len - 1) / 2。所以，回文子串的开始位置就是 i - (len - 1) / 2。
//计算 end 的位置:
//同样地，如果回文子串的长度是 len，右半部分的长度是 len / 2。所以，回文子串的结束位置就是 i + len / 2。
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;

            }
        }
        return s.substr(start, end - start + 1);
    }

    int expandAroundCenter(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }

};

int main05(){
    Solution sol;
    string str = "ababaaaab";
    cout << sol.longestPalindrome(str);
}