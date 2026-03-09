/*
 * @lc app=leetcode.cn id=4 lang=c
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if(nums1Size > nums2Size) {
        int *temp = nums1;
        nums1 = nums2;
        nums2 = temp;
        int tempSize = nums1Size;
        nums1Size = nums2Size;
        nums2Size = tempSize;
    }
    int m = nums1Size, n = nums2Size;
    int left = 0, right = m;
    int half = (m + n + 1) / 2;
    while(left <= right) {
        int i = (left + right) / 2;
        int j = half - i;
        
        int Aleft = (i == 0) ? INT_MIN : nums1[i - 1];
        int Aright = (i == m) ? INT_MAX : nums1[i];
        int Bleft = (j == 0) ? INT_MIN : nums2[j - 1];
        int Bright = (j == n) ? INT_MAX : nums2[j];
        if(Aleft <= Bright && Bleft <= Aright) {
            if((m + n) % 2 == 0) {
                return (MAX(Aleft, Bleft) + MIN(Aright, Bright)) / 2.0;
            } else {
                return (double)MAX(Aleft, Bleft);
            }
        } else if (Aleft > Bright) {
            right = i - 1;
        } else {
            left = i + 1;
        }
    }
    return 0.0;
}
// @lc code=end
/*
 *Accepted
 *2098/2098 cases passed (4 ms)
 *Your runtime beats 21.12 % of c submissions
 *Your memory usage beats 16.1 % of c submissions (11.7 MB)
*/
/*
优化的地方：
    1.从
    if(nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    改为
    if(nums1Size > nums2Size) {
        int *temp = nums1;
        nums1 = nums2;
        nums2 = temp;
        int tempSize = nums1Size;
        nums1Size = nums2Size;
        nums2Size = tempSize;
    }
    避免了函数调用的开销。
    2.使用了宏定义了MAX和MIN函数，而不是直接使用fmin和fmax函数，避免了函数调用的开销。
*/ 

/*
 *Accepted
 *2098/2098 cases passed (0 ms)
 *Your runtime beats 100 % of c submissions
 *Your memory usage beats 13.15 % of c submissions (11.8 MB)
*/