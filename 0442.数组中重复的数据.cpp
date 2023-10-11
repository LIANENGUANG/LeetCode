//
// Created by egl1an on 2023/10/11.
// 思路：出现过一次的直接置为负数，并且用原来的索引代替值
#include "predefs.h"

class Solution {
public:
    vector<int> findDuplicates(vector<int> &nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            // 利用数据范围是[1.n]，因此索引可以从 [0,n-1]
            // 自定义index ，要预判其已经被置为负数的元素
            int index = abs(nums[i]) - 1;
            if(nums[index] > 0) nums[index] = - nums[index];
            else result.push_back(index + 1);
        }
        return result;
    }
};

//class Solution02 {
//public:
//    vector<int> findDuplicates(vector<int> &nums) {
//        map<int, int> numberTofreq;
//        vector<int> result;
//        for (int &num: nums) {
//            numberTofreq[num]++;
//        }
//        for (auto &n: numberTofreq) {
//            if (n.second == 2) {
//                result.push_back(n.first);
//            }
//        }
//        return result;
//    }
//};
int main0442() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    Solution sol;
    for (int &re: sol.findDuplicates(nums)) {
        cout << re << "->";
    }
}