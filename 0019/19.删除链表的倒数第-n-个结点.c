/*
 * @lc app=leetcode.cn id=19 lang=c
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *last = head, *pre = head,*now = head;
    for (int i = 0; i < n; i++) {
        last = last->next;
    }
    while (last) {
        last = last->next;
        pre = now;
        now = now->next;
    }
    if (now == head) {
        head = head->next;
    } else {
        pre->next = now->next;
    }
    free(now);
    return head;
}
// @lc code=end

/*
 * Accepted
 * 208/208 cases passed (0 ms)
 * Your runtime beats 100 % of c submissions
 * Your memory usage beats 29.3 % of c submissions (10.1 MB)
*/