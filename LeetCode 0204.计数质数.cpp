//
// Created by egl1an on 2023/10/21.
//
#include "predefs.h"

class Solution {
public:
    int countPrimes(int n) {
        if( n < 2) return 0; // 对于小于等于 2 的情况，直接返回 0

        // 初始化不二数组，所有的数字默认都是质数
        vector<bool> isPrime(n ,true);

        int count = 0;
        for(int i = 2; i * i < n;++i){
            if(isPrime[i]){
                // 将质数的倍数都标记为非质数
                for(int j = i * i; j < n; j += i){
                    isPrime[j] = false;
                }
            }
        }
        // 统计质数的数量
        for(int i = 2; i < n;++i){
            if(isPrime[i]) count++;
        }
        return count;
    }
};