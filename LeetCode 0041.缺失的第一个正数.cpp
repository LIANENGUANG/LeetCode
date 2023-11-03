//
// Created by egl1an on 2023/11/4.
//
#include "predefs.h"

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();

        // 第一步:过滤掉非正数、0和大于n的数
        // [3 4 -1 1] n = 4
        //  0<3<=4 不用操作
        //  0<4<=4 不用操作
        //  -1<0 则num[2] = 5
        //  0<1<=4 不用操作
        //  因此最终的是[3 4 5 1]
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0 || nums[i] > n) {
                // 将不符合要求的数修改为一个未出现的数
                // 符合要求的数必须是正整数并且不会超过数组的长度，因为长度为 5 的数组最多可以容纳 1 2 3 4 5 五个正整数
                nums[i] = n + 1;
            }
        }

        // 第二步:将数组中的数作为索引,置该索引的数为负数
        // 此时 nums = {3 4 5 1}
        // i = 0|nums[0] = 3|abs[nums[0]] = 3|num = 3|nums[3- 1] = nums[2] = -abs(nums[2]) = -5
        // nums = 3 4 -5 1
        // i = 1|nums[1] = 4|abs[nums[1]] = 4|num = 4|nums[4- 1] = nums[3] = -abs(nums[3]) = -1
        // nums = 3 4 -5 -1
        // i = 2|nums[2] = -5|abs[nums[2]] = 5|num = 5 = n + 1 continue
        // i = 3|nums[3] = -1|abs[nums[3]] = 1|num = 1|nums[1-1] = nums[0] = -abs(nums[0]) = -3
        // nums = -3 4 -5 -1
        for (int i = 0; i < n; ++i) {
            int num = abs(nums[i]);
            if (num == n + 1) continue; // 跳过那些必然不可能是答案的数，不符合条件则必然不可能是答案
            nums[num - 1] = -abs(nums[num - 1]);
        }

        // 第三步:再次遍历数组,第一个正数的索引加1即为缺失的最小正整数
        // nums = -3 4 -5 -1
        // 第一个整数索引为 i = 1时，此时返回的是i + 1 = 1 + 1 = 2
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        // 考虑上面都是负数，说明
        // 到说明少的正好是下一个数，例如数组 1 2 3 4 5 没有出现的最小的正整数就是 6
        return n + 1;
    }
};

