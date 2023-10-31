//
// Created by egl1an on 2023/10/27.
//
#include <unordered_set>
#include "predefs.h"
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sumB = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int delta = (sumA - sumB) / 2;

        unordered_set<int> bobSet(bobSizes.begin(), bobSizes.end());
        for (int x : aliceSizes) {
            if (bobSet.count(x - delta)) {
                return {x, x - delta};
            }
        }
        return {};
    }
};
