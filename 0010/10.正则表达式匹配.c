/*
 * @lc app=leetcode.cn id=10 lang=c
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
#include <stdbool.h>
#include <string.h>

bool isMatch(char* s, char* p) {
    int n = strlen(s);
    int m = strlen(p);
    bool dp[n + 1][m + 1];
    memset(dp, false, sizeof(dp));
    dp[0][0] = true;
    for(int j = 1;j<=m;j++){
        if(p[j-1] == '*'){
            dp[0][j] = dp[0][j-2];
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(p[j-1] == '*'){
                dp[i][j] = dp[i][j-2] ||(dp[i-1][j] && (s[i-1]==p[j-2] || p[j-2]=='.'));
            }else{
                dp[i][j] = (s[i-1]==p[j-1] || p[j-1]=='.') && dp[i-1][j-1];
            }

        }
    }

    return dp[n][m];
}
// @lc code=end

/*
 *Accepted
 *354/354 cases passed (0 ms)
 *Your runtime beats 100 % of c submissions
 *Your memory usage beats 13.24 % of c submissions (8.5 MB)
*/