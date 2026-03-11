/*
 * @lc app=leetcode.cn id=8 lang=c
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
int myAtoi(char* s) {
    long long int res = 0;
    int sign = 1;
    int flag = 0;
    while (*s == ' ') {
        s++;
    }
    if (*s == '-' || *s == '+') {
        sign = (*s == '-') ? -1 : 1;
        s++;
    }
    while (*s!='\0') {
        if (*s < '0' || *s > '9') {
            break;
        }
        res = res * 10 + (*s - '0');
        s++;
        if(res > INT_MAX) {
            if(sign == 1) {
                return INT_MAX;
            }else {
                return INT_MIN;
            }
        }
    }
    return res * sign;
}
// @lc code=end

/*
 *Accepted
 *1096/1096 cases passed (0 ms)
 *Your runtime beats 100 % of c submissions
 *Your memory usage beats 5.49 % of c submissions (9.4 MB)
 */