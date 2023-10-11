//
// Created by egl1an on 2023/10/11.
//
#include "predefs.h"

class Solution {
public:
    vector<string> commonChars(vector<string> &words) {
        map<char, int> result;

        // Initialize result with counts of the first word
        for (char c: words[0]) {
            result[c]++;
        }

        // Process each subsequent word
        for (int i = 1; i < words.size(); i++) {
            map<char, int> charTotimestmp;

            // Count characters of the current word
            for (char c: words[i]) {
                charTotimestmp[c]++;
            }

            // Update result with the minimum of the counts
            for (auto &entry : result) {
                char ch = entry.first;
                result[ch] = min(entry.second, charTotimestmp[ch]);
            }
        }

        // Convert the result map to the output vector
        vector<string> output;
        for (auto &entry : result) {
            for (int i = 0; i < entry.second; i++) {
                output.push_back(string(1, entry.first));
            }
        }

        return output;
    }
};

int main1002() {
    vector<string> words = {"bella", "label", "roller"};
    Solution sol;
    vector<string> result = sol.commonChars(words);
    for (string &s : result) {
        cout << s << " ";
    }
}
