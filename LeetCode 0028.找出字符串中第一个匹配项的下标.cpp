//
// Created by egl1an on 2023/10/18.
//
#include "predefs.h"

class Solution {
public:
    vector<int> computeLpsArray(string needle) {
        int n = needle.size();
        // 初始化 LPS 数组全部为 0，LPS 数组的长度等于模式串的长度
        vector<int> lps(n, 0);
        int i = 1;          // 从needle的第二个字符开始
        int len = 0;       // len表示当前LPS的长度
        /*  i = 1, len = 0: needle[1] = 'B'与needle[0] = 'A'不等，因此lps[1] = 0，i++
            i = 2, len = 0: needle[2] = 'A'与needle[0] = 'A'相等，因此lps[2] = 1，len++，i++
            i = 3, len = 1: needle[3] = 'B'与needle[1] = 'B'相等，因此lps[3] = 2，len++，i++
            i = 4, len = 2: needle[4] = 'C'与needle[2] = 'A'不等，此时len不为0，我们回退到lps[len-1]即lps[1] = 0，再次比较
            i = 4, len = 0: needle[4] = 'C'与needle[0] = 'A'不等，因此lps[4] = 0，i++
            至此，所有字符都已处理完成，得到的LPS数组为[0, 0, 1, 2, 0]。
            */
        while (i < n) {
            if (needle[i] == needle[len]) {
                // 当前字符与len位置的字符相等
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    // 如果len不为0，那么我们退回到上一个LPS值
                    len = lps[len - 1];
                } else {
                    // 如果len为0，则直接设置lps[i]为0，并继续处理下一个字符
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }

/*使用 computeLpsArray 函数来计算needle的LPS数组，我们得到：
lps = [0, 0, 1, 2, 0]
初始化：
i = 0, j = 0
haystack[0] = 'A', needle[0] = 'A', 所以 i++ 和 j++
i = 1, j = 1
haystack[1] = 'B', needle[1] = 'B', 所以 i++ 和 j++
i = 2, j = 2
haystack[2] = 'A', needle[2] = 'A', 所以 i++ 和 j++
i = 3, j = 3
haystack[3] = 'B', needle[3] = 'B', 所以 i++ 和 j++
i = 4, j = 4
haystack[4] = 'A', needle[4] = 'C', 不匹配。此时 j 不是 0，所以 j = lps[j-1] = lps[3] = 2。
i 不变, j = 2
haystack[4] = 'A', needle[2] = 'A', 所以 i++ 和 j++
i = 5, j = 3
haystack[5] = 'B', needle[3] = 'B', 所以 i++ 和 j++
i = 6, j = 4
haystack[6] = 'C', needle[4] = 'C', 所以 i++ 和 j++
i = 7, j = 5
此时 j == n，这意味着我们成功地在 haystack 中匹配了完整的 needle，从索引 i - j = 7 - 5 = 2 处开始。
因此，函数返回 2。可以看到函数第二次匹配时只匹配了第二对 AB，跳过了前一个 AB*/
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();

        // 如果needle是空字符串，根据题目定义应当返回0
        if (n == 0) return 0;

        // 计算needle的LPS数组
        vector<int> lps = computeLpsArray(needle);

        int i = 0, j = 0; // i是haystack的索引，j是needle的索引

        // 开始遍历haystack
        while (i < m) {
            // 当前字符匹配成功
            if (needle[j] == haystack[i]) {
                i++;
                j++;
            }

            // 如果j等于n，意味着needle完全匹配成功
            if (j == n) {
                return i - j; // 返回匹配的起始位置
            }
                // 如果字符不匹配
            else if (i < m && needle[j] != haystack[i]) {
                // 如果j不为0，我们需要回退j的位置
                // 回退的距离是当前j-1位置的LPS值
                if (j != 0) {
                    j = lps[j - 1];
                }
                    // 如果j为0，意味着我们没有其他位置可以回退
                    // 所以移动i到下一个位置
                else {
                    i++;
                }
            }
        }

        // 遍历完haystack都没有完全匹配成功，返回-1
        return -1;
    }
};
