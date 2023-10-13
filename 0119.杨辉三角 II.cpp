//
// Created by egl1an on 2023/10/13.
//
#include "predefs.h"

// however,if you ony need to return a specific row, you can optimize your code so that it only uses
// O(rowindex) space.You cando this by iterating overa single array,updating the array's values with each iteration,
// rather than building the entire Yang Hui triangle.This way ,you don't need to store all the values for the entire
// triangle,but only the values for one row.
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle;
        for (int i = 0; i <= rowIndex; i++) {  // 注意这里的循环条件
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            triangle.push_back(row);
        }
        return triangle[rowIndex];
    }
};
