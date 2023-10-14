//
// Created by egl1an on 2023/10/14.
//
// double pointer method
#include "predefs.h"

class Solution {
public:
    int maxArea(vector<int> &height) {
        int left = 0; // left pointer
        int right = height.size() - 1; // right pointer
        int max_area = 0; // variable to keep track of the max area

        while (left < right) {
            // find the current area
            int current_area = min(height[left], height[right]) * (right - left);
            // update the max area if the current area is larger
            max_area = max(max_area, current_area);
            // move the pointers:always move the smaller one to try and increase the area
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return max_area;
    }
};