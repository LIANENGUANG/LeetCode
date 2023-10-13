//
// Created by egl1an on 2023/10/13.
//
#include "predefs.h"

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int minPrice = INT_MAX; // initialize the minimum price to the maximum integer
        int maxProfit = 0; // initialize the maximum profit to the zero

        for (int price: prices) { // iterate through the prices of each day
            if (price < minPrice) { // if the current price is less than the previous minimum price
                minPrice = price; // update the minimum price
            } else if (price - minPrice > maxProfit){ // otherwise, if the difference between the current price and the minimum price is greater than the maximum profit
                maxProfit = price - minPrice; // update the maximum profit
            }
        }
        return maxProfit;    // return maximum profit
    }
};