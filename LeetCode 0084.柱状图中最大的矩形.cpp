// 单调栈，保持栈中元素的单调性
//
// Created by egl1an on 2023/10/7.
//
#include "predefs.h"

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int ans = 0;
        heights.push_back(0);// 保证栈被弹空
        for (auto height: heights) {
            int accumulatewidth = 0;
            // 栈顶（之前）高度>=当前高度，单调性破坏，确定了栈顶高度的扩展范围，删除栈顶元素
            while (!s.empty()&&s.top().height >= height) {
                accumulatewidth += s.top().width;
                ans = max(ans, s.top().height * accumulatewidth);
                s.pop();
            }
            // 推入的是重新构成的小矩形
            s.push({accumulatewidth + 1, height});
        }
        return ans;
    }

private:
    struct Rect {
        int width;
        int height;
    };
    stack<Rect> s;
};

int main0084(){
    vector<int> heights = {2,1,5,6,2,3};
    Solution sol;
    cout << sol.largestRectangleArea(heights);
}