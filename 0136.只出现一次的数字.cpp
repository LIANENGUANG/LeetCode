//
// Created by egl1an on 2023/10/11.
//
/*异或 (XOR) 是一种二进制操作。其基本规则为：

0 XOR 0 = 0
0 XOR 1 = 1
1 XOR 0 = 1
1 XOR 1 = 0
所以，当你对一个数字和它本身进行异或操作时，你实际上是在对该数字的每一个二进制位和它自己进行异或操作。由于每一位都是与自己进行异或，所以结果总是0。

例如：
假设有一个数字 5，它的二进制表示是 0101。

5 XOR 5 = 0101
XOR
0101
--------
0000 (这就是0)

现在，如果你有两个不同的数字进行异或操作：

例如 5 和 3：

5 (0101)
XOR
3 (0011)
scss
Copy code
0110  (这是数字6)
但是，如果你再次与3进行异或操作：

6 (0110)
XOR
3 (0011)
scss
Copy code
0101  (这就回到了5)
所以，如果一个数字在一个数组中出现两次，那么它对整体的异或结果没有影响，因为它会抵消自己。

这就是为什么当你对一个数组中的所有数字进行异或操作时，唯一没有配对的数字会被留下的原因*/

#include "predefs.h"
class SolutionOne {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int,greater<int>> numberTofreq;
        for(int & num : nums){
            numberTofreq[num]++;
        }
        for(auto n : numberTofreq){
            if(n.second == 1)return n.first;
        }
         return -1;  // 返回map的第一个元素的键
    }
};

class SolutionTwo{
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int & num : nums){
            result ^= num;
        }
        return result;
    }
};

int main0136(){
    vector<int> nums = {2,2,1};
    SolutionOne sol;
    cout << sol.singleNumber(nums);
}