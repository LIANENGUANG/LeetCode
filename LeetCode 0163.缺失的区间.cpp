//
// Created by egl1an on 2023/10/15.
//
#include "predefs.h"

class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int> &nums, int lower, int upper) {
        vector<vector<int>> missingRanges;
        // adding a lower bound and upper bound to simplify logic in the loop
        // dummy node
        nums.insert(nums.begin(), lower - 1);
        nums.push_back(upper + 1);

        for (int i = 1; i < nums.size(); i++) {
            // if adjacent numbers have a difference greater than 1,there is a missing range
            if (nums[i] - nums[i - 1] > 1) {
                vector<int> range;
                // if the range is just a single number, store only that number
                if (nums[i] - nums[i - 1] == 2) {
                    range.push_back(nums[i - 1] + 1);
                    range.push_back(nums[i - 1] + 1);

                } else {// otherwise ,store the start and end of the range
                    range.push_back(nums[i - 1] + 1);
                    range.push_back((nums[i] - 1));
                }
                missingRanges.push_back((range));

            }

        }
        return missingRanges;
    }
};