//
// Created by egl1an on 2023/10/31.
//
#include "predefs.h"
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        // 使用一个unordered_set来存储所有的宝石
        unordered_set<char> jewelSet(jewels.begin(),jewels.end());
        int count = 0;
        // 遍历所有石头
        for(char stone : stones){
            if(jewelSet.find(stone) != jewelSet.end()){
                count++;
            }
        }
        return count;
    }
};