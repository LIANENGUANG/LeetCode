#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int low = 0, high = m;

        while(low <= high) {
           // 1. 二分查找划分 nums1
           int i = (low + high) / 2;
           int j = (m + n + 1) / 2 - i;

           // 2. 获取分割子数组最大和最小值
           // 判断当前子数组是否只有一个元素
           int maxLeft1 = (i == 0) ? INT_MIN : nums1[i-1];
           int minRight1 = (i == m) ? INT_MAX : nums1[i];

           int maxLeft2 = (j == 0) ? INT_MIN : nums2[j-1];
           int minRight2 = (j == n) ? INT_MAX : nums2[j];

           // 3. 判断是否符合要求
           if(maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
               // 4. 计算中位数
               if( (m + n) % 2 == 0 ) {
                   return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
               } else {
                   return max(maxLeft1, maxLeft2);
               }
           }
           else if(maxLeft1 > minRight2) {
               high = i - 1;
           }
           else {
               low = i + 1;
           }
        }

        return 0.0;
    }
};