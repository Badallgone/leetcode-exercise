#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/*
 * @lc app=leetcode.cn id=139 lang=c
 *
 * [139] 单词拆分
 */

// @lc code=start
bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int len = strlen(s);
    bool dp[len+1];
    memset(dp, false, sizeof(dp));

    dp[0] = true;

    for(int i=0;i<=len;i++){
        for(int j=0;j<wordDictSize;j++){
            int wordlen = strlen(wordDict[j]);
            if(i>=wordlen && dp[i-wordlen] && strncmp(s+i-wordlen, wordDict[j], wordlen) == 0){
                dp[i] = true;
                break;
            }
        }
    }
    return dp[len];
}
// @lc code=end

