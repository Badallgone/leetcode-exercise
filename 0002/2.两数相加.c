/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *res = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *cur = res;
    int carry = 0;
    while(l1 || l2 || carry) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        carry = sum / 10;
        sum = sum % 10;
        cur->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        cur->next->val = sum;
        cur = cur->next;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    cur->next = NULL;
    return res->next;
}
// @lc code=end

/*
 *Accepted
 *1569/1569 cases passed (0 ms)
 *Your runtime beats 100 % of c submissions
 *Your memory usage beats 10.34 % of c submissions (13.2 MB)
*/