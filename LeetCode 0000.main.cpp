#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> merged(m + n);

        // 标记三个向量的index值
        int i = 0, j = 0, k = 0;
        // 进行归并排序，保证索引不能超过范围
        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                merged[k++] = nums1[i++];

            } else {
                merged[k++] = nums2[j++];

            }
        }
        // 处理剩余串
        while (i < n) {
            merged[k++] = nums1[i++];

        }
        while (j < m) {
            merged[k++] = nums2[j++];

        }
        // 查找中位数
        if ((m + n) % 2 == 0) {

            return ((merged[(m + n) / 2] + merged[(m + n) / 2 - 1]) / 2.0);
        } else {
            return (merged[(m + n) / 2]);
        }
    }

};

int main00() {
    vector<int> l1 = {1, 3};
    vector<int> l2 = {2};

    Solution sol;
    cout << sol.findMedianSortedArrays(l1, l2);
}
