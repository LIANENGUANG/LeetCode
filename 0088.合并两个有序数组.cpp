//
// Created by egl1an on 2023/10/4.
//
#include "predefs.h"
// 也是过滤器模版，只不过为了原地储存并且利用向量 1 的存储空间我们倒着比较存储大值
// 这么做的原因是当从两个向量中取值时，有可能出现向量 1 中原来已经有的并且有用的元素被提前的覆盖
class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int i = m - 1, j = n - 1;
        for (int k = m + n - 1; k >= 0; k--) {
            if (j < 0 || (i >= 0 && (nums1[i] > nums2[j]))) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
        }
    }
};

int main() {
    vector nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3, n = 3;
    vector nums2 = {2, 5, 6};
    Solution sol;
    sol.merge(nums1, m, nums2, n);
    for (int &num: nums1) {
        cout << num << ' ';
    }
}