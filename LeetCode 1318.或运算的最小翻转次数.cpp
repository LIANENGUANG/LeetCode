//
// Created by egl1an on 2023/10/23.
//
#include "predefs.h"

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        // 当a b c中的任何一个非零时，继续检查
        while (a > 0 || b > 0 || c > 0) {
            // 刚进入循环的时候实际上是比较的第 0 位（从右往左）
            int bit_a = a & 1;
            int bit_b = b & 1;
            int bit_c = c & 1;

            // 如果c的当前位是 0，但是a或b的位是 1，
            // 如果此时a 和 b 的当前位都是 1我们需要反转两次，也正好是bit_a + bit_b
            // 因为此时的bit_a = 1 & 1 = 1,所以结果是 1，bit_b同理，他们相加等于 1 + 1 = 2
            // 如果 a 和 b 当前只有一个是 1，那么另一个是 0，那么bit_a 和 bit_b也只有一个是 1
            // 此时仍旧是bit_a + bit_b = 0 + 1（或者是 1 + 0） = 1

            if (bit_c == 0) {
                flips +=  bit_a + bit_b;
            } else {
                //如果c当前是 1，但是a和b的位都是 0，我们需要反转其中一个即可
                if (bit_b == 0 && bit_a == 0) {
                    flips++;
                }

            }
            // a、b、c三个数继续右移以检查下一个位
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return flips;

    }
};