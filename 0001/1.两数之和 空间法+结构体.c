/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    int val;
    int index;
} Node;

// 2. 结构体比较函数更简单，且能防止减法溢出
int cmp(const void *a, const void *b) {
    Node *nodeA = (Node *)a;
    Node *nodeB = (Node *)b;
    if (nodeA->val < nodeB->val) return -1;
    if (nodeA->val > nodeB->val) return 1;
    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // 一次性申请整块内存，效率极高
    Node* nodes = (Node*)malloc(numsSize * sizeof(Node));
    for (int i = 0; i < numsSize; i++) {
        nodes[i].val = nums[i];
        nodes[i].index = i;
    }

    // 在连续空间上排序，CPU Cache 命中率高
    qsort(nodes, numsSize, sizeof(Node), cmp);

    int left = 0, right = numsSize - 1;
    while (left < right) {
        int sum = nodes[left].val + nodes[right].val;
        if (sum == target) {
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = nodes[left].index;
            result[1] = nodes[right].index;
            *returnSize = 2;
            free(nodes); // 别忘了释放中间变量
            return result;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    *returnSize = 0;
    free(nodes);
    return NULL;
}
// @lc code=end

/*
 *Accepted
 *63/63 cases passed (4 ms)
 *Your runtime beats 91.47 % of c submissions
 *Your memory usage beats 8.67 % of c submissions (10 MB)
*/