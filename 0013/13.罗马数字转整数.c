/*
 * @lc app=leetcode.cn id=13 lang=c
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
int romanToInt(char* s) {
    int result = 0;
    while (*s) {
        if (*s == 'I') {
            if (*(s + 1) == 'V') {
                result += 4;
                s += 2;
            } else if (*(s + 1) == 'X') {
                result += 9;
                s += 2;
            } else {
                result += 1;
                s++;
            }
        } else if (*s == 'V') {
            result += 5;
            s++;
        } else if (*s == 'X') {
            if (*(s + 1) == 'L') {
                result += 40;
                s += 2;
            } else if (*(s + 1) == 'C') {
                result += 90;
                s += 2;
            } else {
                result += 10;
                s++;
            }
        } else if (*s == 'L') {
            result += 50;
            s++;
        } else if (*s == 'C') {
            if (*(s + 1) == 'D') {
                result += 400;
                s += 2;
            } else if (*(s + 1) == 'M') {
                result += 900;
                s += 2;
            } else {
                result += 100;
                s++;
            }
        } else if (*s == 'D') {
            result += 500;
            s++;
        } else if (*s == 'M') {
            result += 1000;
            s++;
        }
    }
    return result;

}
// @lc code=end

/*
 *Accepted
 *3999/3999 cases passed (0 ms)
 *Your runtime beats 100 % of c submissions
 *Your memory usage beats 34.42 % of c submissions (11 MB)
 */