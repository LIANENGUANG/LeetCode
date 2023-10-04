//
// Created by egl1an on 2023/10/4.
//
#include "predefs.h"

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        vector<int> result;
        int i = 0, j = 0;
        while (i < m || j < n) {
            // 什么时候要nums1[i]?或者j出界，或者ij都没出界，而此时nums[i]比较小
            if (j >= n || (i < m && nums1[i] <= nums2[j])) {
                result.push_back(nums1[i]);
                i++;
            } else {
                result.push_back(nums2[j]);
                j++;
            }
        }
        for (int i = 0; i < m + n; i++) nums1[i] = result[i];
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