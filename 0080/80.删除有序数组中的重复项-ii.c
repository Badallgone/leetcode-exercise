/*
 * @lc app=leetcode.cn id=80 lang=c
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
int removeDuplicates(int* nums, int numsSize) {
    if(numsSize <= 2) {
        return numsSize;
    }
    int res = 0;
    int tmp = nums[0];
    int count = 1;
    for (int i = 1; i < numsSize; i++) {
        if(nums[i] == tmp) {
            count++;
        } else {
            tmp = nums[i];
            count = 1;
        }
        if(count <= 2) {
            res++;
        }
        nums[res] = nums[i];
        
    }
    return res+1;
}
// @lc code=end

