/*
 * @lc app=leetcode.cn id=56 lang=c
 *
 * [56] 合并区间
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a,const void *b){
    int *A = *(int**)a;
    int *B = *(int**)b;
    return A[0] - B[0];
}


// 先排序，再合并
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if(intervalsSize <= 0){
        return NULL;
    }
    qsort(intervals, intervalsSize, sizeof(int *), cmp);
    int **res = (int**)malloc(sizeof(int*)*intervalsSize);
    for(int i=0;i<intervalsSize;i++){
        res[i] = (int*)malloc(sizeof(int)*2);
    }

    int count = 0;
    res[count][0] = intervals[0][0];
    res[count][1] = intervals[0][1];
    for(int i=1;i<intervalsSize;i++){
        if(res[count][1] >= intervals[i][0]){
            res[count][1] = res[count][1] > intervals[i][1] ? res[count][1] : intervals[i][1];
        }else{
            count++;
            res[count][0] = intervals[i][0];
            res[count][1] = intervals[i][1];
        }
    }
    *returnSize = count + 1;
    *returnColumnSizes = (int*)malloc(sizeof(int)*(*returnSize));
    for(int i=0;i<*returnSize;i++){
        (*returnColumnSizes)[i] = 2;
    }
    return res;
}
// @lc code=end

