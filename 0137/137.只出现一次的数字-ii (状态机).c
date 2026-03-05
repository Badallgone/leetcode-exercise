/*
 * @lc app=leetcode.cn id=137 lang=c
 *
 * [137] 只出现一次的数字 II
 */
// 使用位运算模拟三进制状态机 (Digital Logic Design)
// ones 记录所有位中出现 1 次的掩码
// twos 记录所有位中出现 2 次的掩码
// 状态转换：00 -> 01 -> 10 -> 00 (分别对应出现 0, 1, 2 次)
// 时间复杂度 O(N)，但是是一次遍历，比逐位统计快 32 倍

// @lc code=start
int singleNumber(int* nums, int numsSize) {
    int ones = 0, twos = 0;
    for(int i = 0; i < numsSize; i++){
        ones = (ones ^ nums[i]) & ~twos;
        twos = (twos ^ nums[i]) & ~ones;
    }
    return ones;
}
// @lc code=end

