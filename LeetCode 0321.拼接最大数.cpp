//
// Created by egl1an on 2023/11/8.
//
#include "predefs.h"

class Solution {
public:
    vector<int> merge(vector<int> &subsequence1, vector<int> &subsequence2) {
        vector<int> merged;
        auto i = subsequence1.begin(), j = subsequence2.end();
        // 当两个子序列都非空时，选择两者之间较大的数
        // 两个子序列都还未比较到最后
        while(i != subsequence1.end() || j != subsequence2.end()){
            // 比较两个子序列的当前的数字，将较大的数字添加到合并序列中
            // 如果当前数字相等，则需要比较后续数字来决定决定选择那个序列的数字
            auto& it = lexicographical_compare(i, subsequence1.end(),j,subsequence2.end()) ? j : i;
            merged.push_back(*it);
            // 注意这里的it是指针，每次增加的是那个较大的迭代器i/j
            ++it;
        }
    return merged;
    }

    // 用单调栈来找出单个数组中的最大子序列
    vector<int> maxSubsequence(vector<int> &nums, int k) {
        int len = nums.size();
        // 初始化栈大小为k，因为现在的目标是找到长度为k的最大子序列
        vector<int> stack(k, 0);
        int top = -1;
        // remain 代表能够跳过几个数字，因为不能全部跳过了，不然的话就没办法构成一个k大小的子序列
        // 也就是说最终留下k个数我们要跳过多少个数，答案就是len - k个数
        int remain = len - k;
        for (int i = 0; i < len; ++i) {
            int num = nums[i];
            // 当栈不为空，且栈顶元素小于当前元素，且还有可以丢弃的数字时，弹出栈顶元素
            while (top >= 0 && stack[top] < num && remain > 0) {
                --top;
                --remain;
            }
            // 如果栈没有满，将当前元素入栈
            // 不满足上述while循环说明三者必有一个不成立
            if (top < k - 1) {
                // 先给top值加 1，然后赋值
                stack[++top] = num;
            } else {
                // 如果栈顶元素的值大于当前num值，则为了维护单调递增栈直接跳过该元素
                --remain;
            }
        }
        return stack;
    }

    vector<int> maxNumber(vector<int> nums1, vector<int> nums2, int k) {
        // 初始化最大序列为k个0，用来记录当前找到的最大序列
        vector<int> maxSequence(k, 0);

        // 计算从nums1中至少需要取多少个数字，这个数量不能小于0，也不能大于k减去nums2的长度
        int start = max(0, k - static_cast<int>(nums2.size()));

        // 计算从nums1中最多可以取多少个数字，这个数量不能大于k，也不能大于nums1的长度
        int end = min(k, static_cast<int>(nums1.size()));

        // 尝试从nums1中取出i个数字，从 nums2中取k - i个数字，i的取值范围是[start,end]
        for(int i = start; i <= end; ++i){
            // 从nums1中取i个数字构成的最大子序列
            vector<int> subsequence1 = maxSubsequence(nums1,i);
            // 从nums2中取k - i个数字构成的最大子序列
            vector<int> subsequence2 = maxSubsequence(nums2,k - i);
            // 将两个子序列合并成一个序列
            vector<int> merged = merge(subsequence1,subsequence2);
            // 如果当前合并的序列比之前的最大序列大，则更新最大序列
            if(lexicographical_compare(maxSequence.begin(),maxSequence.end(), merged.begin(), merged.end())){
                maxSequence = merged;
            }
        }
        return maxSequence;
    }
};