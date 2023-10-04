#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result;
        map<int, int> numToIndex;
        for (int i = 0; i < nums.size(); i++) {
            // target > nums[i]
            int complement = target - nums[i];
            // 如果在 numToIndex 这个容器中未找到一个键等于 complement 的元素，
            // 那么 find 函数将返回一个指向容器末尾位置的迭代器（即 numToIndex.end()），并且条件不成立（返回 false）。
            if (numToIndex.find(complement) != numToIndex.end()) {
                // numToindex[complement]  == value
                result.push_back(numToIndex[complement]);
                result.push_back(i);
                return result;
            }
            numToIndex[nums[i]] = i;
        }
        return result;
    }
};

int main01() {
    vector<int> num = {2, 7, 11, 15};
    int target = 13;

    Solution solution;
    vector<int> result = solution.twoSum(num, target);

    cout << "Indices of the two numbers that add up to target: " << result[0] << " and " << result[1] << endl;

    // 打印 map 的内容

    return 0;
}