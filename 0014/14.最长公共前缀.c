/*
 * @lc app=leetcode.cn id=14 lang=c
 *
 * [14] 最长公共前缀
 */

// @lc code=start
char* longestCommonPrefix(char** strs, int strsSize) {
    char *prefix = (char *)malloc(200 * sizeof(char));
    if (strsSize == 0) {
        prefix[0] = '\0';
        return prefix;
    }
    int len = strlen(strs[0]);
    memcpy(prefix, strs[0], len+1);
    for(int i = 1; i < strsSize; i++) {
        int j = 0;
        while (j < len && strs[i][j] != '\0' && prefix[j] == strs[i][j]) {
            j++;
        }
        prefix[j] = '\0';
        len = j;
    }
    return prefix;
}
// @lc code=end

/*
 *Accepted
 *126/126 cases passed (0 ms)
 *Your runtime beats 100 % of c submissions
 *Your memory usage beats 28.52 % of c submissions (8.7 MB)
 */