//
// Created by egl1an on 2023/10/3.
//
// 双指针法
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) { return false; }

        string str = to_string(x);

        int left = 0;
        int right = str.size() - 1;

        while (left< right) {
            if(str[left] != str[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;

    }
};
int main09() {
    Solution solution;

    int testNumber = 121; // 可以修改为要测试的整数
    // 布尔值没有办法直接打印，需要通过if (result)的办法来选择性的打印
    bool result = solution.isPalindrome(testNumber);

    if (result) {
        cout << testNumber << " is a palindrome." << endl;
    } else {
        cout << testNumber << " is not a palindrome." << endl;
    }

    return 0;
}