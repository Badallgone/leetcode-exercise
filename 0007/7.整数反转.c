/*
 * @lc app=leetcode.cn id=7 lang=c
 *
 * [7] 整数反转
 */

// @lc code=start
int reverse(int x) {
    long long int res=0;
    int flag = 1;
    long long int tmp_x = x;
    /* 这里最好使用 long long int 类型直接接手x，要么在下面的取正数的过程中，会导致x溢出 */
    if(tmp_x<0){
        flag = -1;
        tmp_x = -tmp_x;
    }
    while(tmp_x){
        res = res * 10 + tmp_x % 10;
        tmp_x /= 10;
    }
    if(res > INT_MAX || res < INT_MIN) return 0;
    return res * flag;
}
// @lc code=end

/*
 *Accepted
 *1045/1045 cases passed (0 ms)
 *Your runtime beats 100 % of c submissions
 *Your memory usage beats 19.4 % of c submissions (9 MB)
*/