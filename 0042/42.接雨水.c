/*
 * @lc app=leetcode.cn id=42 lang=c
 *
 * [42] 接雨水
 */

// @lc code=start
int trap(int* height, int heightSize) {
    if (heightSize <= 2){
        return 0;
    }
    int ans = 0;
    int left = 0, right = heightSize - 1;
    int leftMax = 0, rightMax = 0;
    while (left < right) {
        if(height[left] < height[right]) {
            if(height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                ans += leftMax - height[left];
            }
            left++;
        } else {
            if(height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                ans += rightMax - height[right];
            }
            right--;
        }
    }
    return ans;
}
// @lc code=end
/*
 *Accepted
 *324/324 cases passed (0 ms)
 *Your runtime beats 100 % of c submissions
 *Your memory usage beats 28.08 % of c submissions (10.3 MB)
*/