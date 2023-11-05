//
// Created by egl1an on 2023/11/5.
//

#include "predefs.h"
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    // 创建哈希映射，存储arr2中元素的索引
    // <key:arr[i],value:i(index)>
    unordered_map<int, int> rank;
    for(int i = 0; i < arr2.size();++i){
        rank[arr2[i]] = i;
    }

    // 对arr1进行排序
    sort(arr1.begin(),arr1.end(),[&rank](int a, int b){
        // 如果两个元素都在arr2当中，则按照他们在arr2中的顺序排序
        if(rank.count(a) && rank.count(b)) {
            return rank[a] < rank[b];
        }
        // 如果只有一个元素在arr2中，则这个元素优先
        if(rank.count(a)){
            return true;
        }
        if(rank.count(b)){
            return false;
        }
        // 如果两个元素都不在arr2中，则按数值大小排序
        return a < b;
    });
    return arr1;
    }
};