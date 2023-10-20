//
// Created by egl1an on 2023/10/12.
//
#include "predefs.h"

class Solution {
public:
    string sortString(string s) {
        vector<int> count(26, 0);
        for (char c: s) {
            // store the number of each character in a 26-dimensional vector
            count[c - 'a']++;
        }
        string result;
        while (result.size() < s.size()) {
            // Traverse in ascending order
            for (int i = 0; i < 26; i++) {
                if (count[i] > 0) {
                    result.push_back(i + 'a');
                    count[i]--;
                }
            }
            // Traverse in descending order
            for (int i = 25; i >= 0; i--) {
                if (count[i] > 0) {
                    result.push_back(i + 'a');
                    count[i]--;
                }
            }
        }
        return result;


    }
};

int main1370() {
    string s = "aaaabbbbcccc";
    Solution sol;
    for(auto ch : sol.sortString(s)){
        cout << ch << endl;
    };
}