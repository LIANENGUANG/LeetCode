//
// Created by egl1an on 2023/10/13.
//
#include "predefs.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1); // create a row of size i + 1,with all elements initialized to 1
            for (int j = 1; j < i; j++) { // for each middle element
                row[j] = triangle[i - 1][j - 1] +
                         triangle[i - 1][j];// it is equal to the sum of the two adjacent elements of the previous row
            }
            triangle.push_back(row); //  add this line to the triangle
        }
        return triangle;
    }
};