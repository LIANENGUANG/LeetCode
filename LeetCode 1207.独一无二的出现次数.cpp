//
// Created by egl1an on 2023/10/11.
//
#include "predefs.h"
// 核心：把元素值作为索引
// 开辟set用于存储唯一次数，而map用于存储键值对，数字和频率
class Solution {
public:
    bool uniqueOccurrences(vector<int> &arr) {
        set<int> result;
        map<int, int> numberTotimes;
        // 统计每个数字的出现次数
        for (int &number: arr) {
            numberTotimes[number]++;
        }
        for(auto &[_,times]:numberTotimes){
            if(result.find(times)!=result.end()){
                return false;
            }
            else result.insert(times);
        }
        return true;
    }
};
int main1207(){
    vector<int> arr = {1,2,2,1,1,3};
    Solution sol;

    bool re = sol.uniqueOccurrences(arr);
    cout <<re;

}