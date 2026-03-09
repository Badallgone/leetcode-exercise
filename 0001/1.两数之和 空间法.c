/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(const void *a, const void *b) {
    return (*(int **)a)[0] - (*(int **)b)[0];
}

/* 空间换时间，先排序再查找 */ 
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int **index = (int **)malloc(numsSize * sizeof(int *));
    for (int i = 0; i < numsSize; i++) {
        index[i] = (int *)malloc(2 * sizeof(int));
        index[i][0] = nums[i];
        index[i][1] = i;
    }
    qsort(index, numsSize, sizeof(int *), cmp);

    int *result = (int *)malloc(2 * sizeof(int));
    int flag = 0;
    int left = 0, right = numsSize - 1;
    while(left < right) {
        int sum = index[left][0] + index[right][0];
        if (sum == target) {
            result[0] = index[left][1];
            result[1] = index[right][1];
            flag = 1;
            break;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    *returnSize = flag ? 2 : 0;
    return flag ? result : NULL;
}
// @lc code=end

/*
 *Accepted
 *63/63 cases passed (12 ms)
 *Your runtime beats 85.8 % of c submissions
 *Your memory usage beats 6.5 % of c submissions (10.8 MB)
*/