/*
 * @lc app=leetcode.cn id=137 lang=c
 *
 * [137] 只出现一次的数字 II
 */
// 将数字转换成二进制数进行考虑
// 记录每一位上1的个数，最后对3取模，如果不为0说明只出现一次的数字在这一位上是1
// 将数据强转为无符号整数进行位运算，避免符号位干扰，且符合位运算规范
// 时间复杂度O(n)，空间复杂度O(1)

// @lc code=start
int singleNumber(int* nums, int numsSize) {
    int res = 0;
    int count[32] = {0};
    for(int i=0;i<numsSize;i++){
        for(int j=0;j<32;j++){
            // 使用 unsigned int 进行逻辑右移，避免符号位干扰，且符合位运算规范
            if(((unsigned int)nums[i] >> j) & 1){
                count[j]++;
            }
        }
    }
    for(int i=0;i<32;i++){
        if(count[i] % 3 != 0){
            // 使用 unsigned int 1 防止左移溢出 (1<<31 在 int 中是未定义行为)
            res |= ((unsigned int)1 << i);
        }
    }
    return res;
}
// @lc code=end

