/*
 * @lc app=leetcode.cn id=16 lang=c
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int ans = nums[0] + nums[1] + nums[2];

    for(int i = 0; i < numsSize - 2; i++) {
        if(i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        // 剪枝
        int minsum = nums[i] + nums[i + 1] + nums[i + 2];
        if(minsum > target) {
            if(abs(minsum - target) < abs(ans - target)) {
                ans = minsum;
            }
            break;
        }

        int maxsum = nums[i] + nums[numsSize - 1] + nums[numsSize - 2];
        if(maxsum < target) {
            if(abs(maxsum - target) < abs(ans - target)) {
                ans = maxsum;
            }
            continue;
        }

        int left = i + 1, right = numsSize - 1;
        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == target) {
                return sum;
            }
            
            if(abs(sum - target) < abs(ans - target)) {
                ans = sum;
            }

            if(sum < target) {
                left++;
                while(left < right && nums[left] == nums[left - 1]) {
                    left++;
                }
            }

            if(sum > target) {
                right--;
                while(left < right && nums[right] == nums[right + 1]) {
                    right--;
                }
            }
        }
    }
    return ans;
}
// @lc code=end

/*
 *Accepted
 *107/107 cases passed (3 ms)
 *Your runtime beats 92.04 % of c submissions
 *Your memory usage beats 12.75 % of c submissions (9 MB)
*/