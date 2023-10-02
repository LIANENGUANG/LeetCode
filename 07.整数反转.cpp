//
// Created by egl1an on 2023/10/2.
//
#include <iostream>
#include <stdio.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while (x != 0 ){
            res = res * 10 + x % 10;
            x /= 10;
        }
        if ( res < INT_MIN || res > INT_MAX){
            return 0;
        }
        return (int)res;
    }
};

int main07() {
    int a = -123;
    Solution sol;
    cout << sol.reverse(a) << endl;
}