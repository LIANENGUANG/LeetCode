//
// Created by egl1an on 2023/10/4.
//
#include "vector"
#include "iostream"
using namespace std;
// 快慢指针法
// 保序操作数组：过滤器思想，只是条件不同，模版是一样的
class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int n = 0;
        for (int i = 0; i < nums.size(); i++) {
            // 第一个数肯定要，当前的数和前面的不一样的我们也要，确保边界不要超出，并且是原地操作
            if (i == 0 || nums[i] != nums[i - 1]) {
                nums[n] = nums[i];
                n++;
            }
        }
        return n;

    }
};

int main26(){
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    Solution sol;
    cout << sol.removeDuplicates(nums);
}