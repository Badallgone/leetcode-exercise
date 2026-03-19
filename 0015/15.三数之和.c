/*
 * @lc app=leetcode.cn id=15 lang=c
 *
 * [15] 三数之和
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int **result = (int**)malloc(sizeof(int*) * numsSize * numsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * numsSize * numsSize);
    *returnSize = 0;
    for(int i=0; i<numsSize-2; i++) {
        if(i > 0 && nums[i] == nums[i-1]) continue;
        if(nums[i] > 0) break;
        int left = i + 1, right = numsSize - 1;
        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == 0) {
                result[*returnSize] = (int*)malloc(sizeof(int) * 3);
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                left++;
                right--;
                while(left < right && nums[left] == nums[left-1]) left++;
                while(left < right && nums[right] == nums[right+1]) right--;
            } else if(sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    return result;
}
// @lc code=end

/*
 *Accepted
 *316/316 cases passed (43 ms)
 *Your runtime beats 88.64 % of c submissions
 *Your memory usage beats 54 % of c submissions (38.5 MB)
*/