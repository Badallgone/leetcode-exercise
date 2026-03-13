/*
 * @lc app=leetcode.cn id=11 lang=c
 *
 * [11] 盛最多水的容器
 */

// @lc code=start

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

int maxArea(int* height, int heightSize) {
    int max_res = 0;
    int left = 0, right = heightSize - 1;
    while (left < right) {
        // 通过直接取值避免了多次的数组访问，提升性能
        int left_height = height[left];
        int right_height = height[right];
        int area = (right-left)*(MIN(left_height, right_height));
        max_res = MAX(max_res, area);
        if (left_height < right_height) {
            //加速的关键，跳过一些不必要的计算
            while(left < right && height[left] <= left_height) {
                left++;
            }
        } else {
            while (left < right && height[right]<=right_height) {
                right--;
            }
        }
    }
    return max_res;
}
// @lc code=end

/*
 *Accepted
 *65/65 cases passed (0 ms)
 *Your runtime beats 100 % of c submissions
 *Your memory usage beats 5.56 % of c submissions (14.6 MB)
*/
