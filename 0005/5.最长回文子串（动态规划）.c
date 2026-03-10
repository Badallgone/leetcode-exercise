/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 */

// @lc code=start
//动态规划
char* longestPalindrome(char* s) {
    int dp[1001][1001] = {0};
    int max_len = 1;
    int ans_start = 0;
    int n = strlen(s);
    for (int i = 0; s[i]; i++) {
        dp[i][i] = 1;
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = 1;
            max_len = 2;
            ans_start = i;
        }
    }

    for(int i = n-3;i>=0;i--){
        for(int j = i+2;j<n;j++){
            if(s[i] == s[j] && dp[i+1][j-1]){
                dp[i][j] = 1;
                if(j - i + 1 > max_len){
                    max_len = j - i + 1;
                    ans_start = i;
                }
            }
        }
    }

    s[ans_start + max_len] = '\0';
    return s + ans_start;

}
// @lc code=end

/*
 *Accepted
 *143/143 cases passed (111 ms)
 *Your runtime beats 38.03 % of c submissions
 *Your memory usage beats 10.06 % of c submissions (12.7 MB)
*/