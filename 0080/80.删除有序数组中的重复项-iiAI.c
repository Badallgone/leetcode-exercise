/*
 * @lc app=leetcode.cn id=80 lang=c
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start

// 代码更简洁了，但是由于增加了对内存的访问，性能反而下降了
// 同时由于比较的是index-2位置的元素，而不是当前元素的前一个元素，
// 所以在相比于直接比较nums[i]和nums[i-1]的方案中，增加了对内存的访问，
// 因为原来的连续两个元素之间可能是保存在寄存器中的
int removeDuplicates(int* nums, int numsSize) {
    /*-------- AI1.0 版本---------------*/
    // if(numsSize <= 2) {
    //     return numsSize;
    // }
    
    // // index 指向下一个要放置有效元素的位置，前两个元素默认有效
    // int index = 2;
    // for (int i = 2; i < numsSize; i++) {
    //     // 如果当前元素 nums[i] 与已构建好的数组倒数第二个元素不同
    //     // 说明 nums[i] 是合法的（它是第1个或第2个重复项，或者是全新的数值）
    //     if (nums[i] != nums[index - 2]) {
    //         nums[index++] = nums[i];
    //     }
    // }
    // return index;
    
    /*-------- AI2.0 版本---------------*/
    if (numsSize <= 2) {
        return numsSize;
    }
    
    int index = 1;
    int count = 1;
    
    for (int i = 1; i < numsSize; i++) {
        // 利用 i-1 比较，缓存命中率极高
        if (nums[i] == nums[i-1]) {
            count++;
        } else {
            count = 1;
        }
        
        if (count <= 2) {
            // 核心优化：如果 element 在正确的位置，就没有必要自己赋值给自己
            // 这极大地减少了内存写操作
            if (index != i) {
                nums[index] = nums[i];
            }
            index++;
        }
    }
    return index;
}
// @lc code=end

