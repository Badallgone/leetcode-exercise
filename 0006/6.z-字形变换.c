/*
 * @lc app=leetcode.cn id=6 lang=c
 *
 * [6] Z 字形变换
 */

// @lc code=start
char* convert(char* s, int numRows) {
    int n = strlen(s);
    char *res = (char*)malloc(sizeof(char) * (n + 1));
    int index = 0;
    if (numRows == 1) {
        strcpy(res, s);
        return res;
    }
    int cycleLen = 2 * numRows - 2;
    for(int i = 0; i < numRows; i++) {
        int k=i;
        if(i==0 || i==numRows-1) {
            while(k < n) {
                res[index++] = s[k];
                k += cycleLen;
            }
        } else {
            int kk = cycleLen - i;
            while(k < n) {
                res[index++] = s[k];
                if(kk < n) {
                    res[index++] = s[kk];
                }
                k += cycleLen;
                kk += cycleLen;
            }
        }
    }
    res[index] = '\0';
    return res;
}
// @lc code=end

/*
 *Accepted
 *1157/1157 cases passed (0 ms)
 *Your runtime beats 100 % of c submissions
 *Your memory usage beats 54.84 % of c submissions (9.4 MB)
 */