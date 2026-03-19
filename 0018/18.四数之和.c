/*
 * @lc app=leetcode.cn id=18 lang=c
 *
 * [18] 四数之和
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

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int **result = (int**)malloc(sizeof(int*) * 1000);
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * 1000);
    if(numsSize < 4) {
        return result;
    }

    for(int i=0; i<numsSize-3; i++) {
        if(i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        long long int minSum = (long long int)nums[i] + (long long int)nums[i+1] + (long long int)nums[i+2] + (long long int)nums[i+3];
        if(minSum > (long long int)target) {
            break;
        }
        long long int maxSum = (long long int)nums[i] + (long long int)nums[numsSize-1] + (long long int)nums[numsSize-2] + (long long int)nums[numsSize-3];
        if(maxSum < (long long int)target) {
            continue;
        }
        for(int j=i+1; j<numsSize-2; j++) {
            if(j > i+1 && nums[j] == nums[j-1]) {
                continue;
            }
            if((long long int)nums[i] + (long long int)nums[j] + (long long int)nums[j+1] + (long long int)nums[j+2] > (long long int)target) {
                break;
            }
            if((long long int)nums[i] + (long long int)nums[j] + (long long int)nums[numsSize-1] + (long long int)nums[numsSize-2] < (long long int)target) {
                continue;
            }

            int left = j + 1;
            int right = numsSize - 1;
            while(left < right) {
                int sum = (long long int)nums[i] + (long long int)nums[j] + (long long int)nums[left] + (long long int)nums[right];
                if(sum == (long long int)target) {
                    result[*returnSize] = (int*)malloc(sizeof(int) * 4);
                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[j];
                    result[*returnSize][2] = nums[left];
                    result[*returnSize][3] = nums[right];
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;
                    while(left < right && nums[left] == nums[left+1]) {
                        left++;
                    }
                    while(left < right && nums[right] == nums[right-1]) {
                        right--;
                    }
                    left++;
                    right--;
                } else if(sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }
    return result;
    
}
// @lc code=end

/*
 * Accepted
 * 294/294 cases passed (0 ms)
 * Your runtime beats 100 % of c submissions
 * Your memory usage beats 49.51 % of c submissions (16 MB)
*/