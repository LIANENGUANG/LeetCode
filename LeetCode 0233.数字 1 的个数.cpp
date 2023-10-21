//
// Created by egl1an on 2023/10/21.
//
#include "predefs.h"
class Solution {
public:
int countDigitOne(int n) {
    if(n <= 0) return 0;

    long long count = 0;
    for(long long i = 1; i <= n; i *= 10) {
        long long divider = i * 10;
        count += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
    }
    return count;
}
};