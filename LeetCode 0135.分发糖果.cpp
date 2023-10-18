//
// Created by egl1an on 2023/10/18.
//
#include "predefs.h"

class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        // 初始化，每个孩子刚开始至少分配一个糖果
        vector<int> left(n, 1), right(n, 1);

        // 第一次从左至右
        for (int i = 1; i < n; i++) {
            // 当前孩子评分大于其左侧孩子的评分，则应该使这一轮的数组当前孩子比左边孩子大 1 一个
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }
        // 第二次从右至左
        for (int i = n - 2; i >= 0; i--) {
            // 与之前的同理
            if(ratings[i] > ratings[i+1]){
                right[i] = right[i+1] + 1;
            }
        }
        int total_candies = 0;
        for(int i = 0; i < n;i++){
            total_candies += max(left[i],right[i]);
        }
        return total_candies;
    }
};