/*
 * @lc app=leetcode.cn id=17 lang=c
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char *mapping[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

char** letterCombinations(char* digits, int* returnSize) {
    char **res = (char **)malloc(sizeof(char *) * 300);
    int len = strlen(digits);
    if (len == 0) {
        *returnSize = 0;
        return res;
    }
    int count = 0;
    for(int i=0;i<len;i++) {
        int num = digits[i] - '0';
        char *str = mapping[num];
        int str_len = strlen(str);
        if (count == 0) {
            for(int j=0;j<str_len;j++) {
                res[count] = (char *)malloc(sizeof(char) * 5);
                res[count][0] = str[j];
                res[count][1] = '\0';
                count++;
            }
        } else {
            int temp_count = count;
            for(int k=0;k<temp_count;k++) {
                res[k][i] = str[0];
                res[k][i + 1] = '\0';
            }
            for(int j=1;j<str_len;j++) {
                for(int k=0;k<temp_count;k++) {
                    res[count] = (char *)malloc(sizeof(char) * 5);
                    strcpy(res[count], res[k]);
                    res[count][i] = str[j];
                    res[count][i + 1] = '\0';
                    count++;
                }
            }
        }
    }
    *returnSize = count;
    return res;
}
// @lc code=end

/*
 *Accepted
 *24/24 cases passed (0 ms)
 *Your runtime beats 100 % of c submissions
 *Your memory usage beats 44.26 % of c submissions (8.9 MB)
*/