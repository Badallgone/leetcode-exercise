/*
 * @lc app=leetcode.cn id=9 lang=c
 *
 * [9] 回文数
 */

// @lc code=start
bool isPalindrome(int x) {
    if(x < 0) return false;
    long long int num = x;
    long long int res = 0;
    while(num) {
        res = res * 10 + num % 10;
        num /= 10;
    }
    return res == x;
}
// @lc code=end

/*
 *Accepted
 *11511/11511 cases passed (0 ms)
 *Your runtime beats 100 % of c submissions
 *Your memory usage beats 36.1 % of c submissions (8.8 MB)
 */