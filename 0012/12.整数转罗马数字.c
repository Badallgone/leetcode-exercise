/*
 * @lc app=leetcode.cn id=12 lang=c
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
char* intToRoman(int num) {
    char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* result = (char*)malloc(16 * sizeof(char)); // 结果字符串
    char* p = result; // 指向结果字符串的指针

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            char *symbol = symbols[i];
            while (*symbol) {
                *p++ = *symbol++; // 将符号添加到结果字符串
            }
            num -= values[i]; // 减去对应的值
        }
    }
    *p = '\0'; // 结束字符串
    return result;

}
// @lc code=end

/*
 *Accepted
 *3999/3999 cases passed (3 ms)
 *Your runtime beats 50.16 % of c submissions
 *Your memory usage beats 8.6 % of c submissions (9.9 MB)
*/