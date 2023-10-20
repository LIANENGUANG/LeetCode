//
// Created by egl1an on 2023/10/7.
//
#include "predefs.h"
class Solution {
public:
    int trap(vector<int>& heights) {
        int ans = 0;
        for (int height : heights) {
            int accumulatewidth = 0;
            while (!s.empty() && s.top().height <= height) {
                int bottom = s.top().height;
                accumulatewidth += s.top().width;
                s.pop();
                if (s.empty()) continue;  // 水从左边流走了
                // 以bottom 为底的横块水，最高可以到up，左右两侧高度的最小值
                int up = min(height, s.top().height);
                ans += accumulatewidth * (up - bottom);
            }
            accumulatewidth += 1;  // update width
            s.push({accumulatewidth, height});
        }
        return ans;  // Return the accumulated water
    }

private:
    struct Rect {
        int width;
        int height;
    };
    stack<Rect> s;
};
