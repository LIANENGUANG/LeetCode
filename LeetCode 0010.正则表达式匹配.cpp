//
// Created by egl1an on 2023/10/3.
//
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        dp[0][0] = true;

        for(int i = 0; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(p[j-1] != '*') {
                    dp[i][j] = i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                } else {
                    dp[i][j] = dp[i][j-2] || (i > 0 && dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
                }
            }
        }
        return dp[m][n];
    }
};
