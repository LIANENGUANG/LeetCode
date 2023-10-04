//
// Created by egl1an on 2023/9/30.
//
// 这个问题可以使用滑动窗口方法来解决。我们可以使用两个指针来定义一个窗口，并使用一个集合来存储窗口中的字符。
// 然后，我们移动右指针来扩大窗口，直到遇到重复字符为止。此时，我们移动左指针来缩小窗口。
#include <iostream>
//unordered_set是C++标准库中的一个容器，它用于存储唯一的元素。
//它允许在平均常数时间复杂度内进行插入、删除和查找操作。
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int left = 0, right = 0;
        int maxLength = 0;

        while (right < s.length()) {
            char r = s[right];
            // 若找到末尾都没有找到r，window.find返回window.end()迭代器,此时二者相等，不再进入循环
            // 而是直接跳过这个循环到下面那个insert操作里去
            // 相当于此时的串内没有当前的重复字符，应该重新定义边界点
            // 如果确实找到了重复字符，那么应该处理当前的滑动窗口
            // 在上述while循环内：
            // char l = s[left]: 取出左边界的字符。
            // window.erase(l): 从window集合中移除该字符。
            // left++: 将左边界向右移动一位，从而缩小窗口，直到字符r不再窗口内为止。
            while (window.find(r) != window.end()) {
                char l = s[left];
                window.erase(l);
                left++;
            }
            window.insert(r);
            // 更新最长子串的长度值,比较当前窗口长度和已经记录的最长的长度大小，以便判断是否更新最大值
            maxLength = max(maxLength, right - left + 1);
            right++;
        }
        return maxLength;
    }
};

int main03() {
    Solution sol;
    string s = "abcabcbb";
    int len = sol.lengthOfLongestSubstring(s);
    cout << len << endl;
}
//初始化:
//unordered_set<char> window: 存储当前窗口内的字符。由于它是一个集合，所以不允许有重复的元素。
//int left = 0, right = 0: 定义了滑动窗口的左边界和右边界。起初，两者都指向字符串的开始。
//int maxLength = 0: 存储迄今为止找到的最长无重复字符子字符串的长度。
//开始滑动窗口:
//使用while循环，该循环继续进行，直到右边界right超出字符串的长度。
//检查右边界的字符:
//char r = s[right]: 取出右边界的字符。
//检查字符r是否在当前窗口中:
//while (window.find(r) != window.end()): 如果字符r已经在当前窗口内，这意味着我们有一个重复字符。
//处理重复字符:
//在上述while循环内：
//char l = s[left]: 取出左边界的字符。
//window.erase(l): 从window集合中移除该字符。
//left++: 将左边界向右移动一位，从而缩小窗口，直到字符r不再窗口内为止。
//更新窗口和最大长度:
//window.insert(r): 将字符r加入到window中，因为它现在是窗口的新右边界字符。
//maxLength = max(maxLength, right - left + 1): 更新maxLength，其中right - left + 1计算当前窗口的长度。
//这里应该是right - left + 1而不是right - left - 1，因为要包括两个边界在内。
//right++: 将右边界向右移动一位，从而扩大窗口。
//返回结果:
//return maxLength: 当循环结束后，返回找到的最长无重复字符子字符串的长度。
//注意: 在代码中，maxLength = max(maxLength, right - left -1);应该修正为maxLength = max(maxLength, right - left + 1);
//才能得到正确的结果。