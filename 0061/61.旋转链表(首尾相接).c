/*
 * @lc app=leetcode.cn id=61 lang=c
 *
 * [61] 旋转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head == NULL || head->next == NULL || k == 0) {
        return head;
    }

    int len = 1;
    struct ListNode* old_tail = head;
    while(old_tail->next) {
        len++;
        old_tail = old_tail->next;
    }

    k = k % len;
    if(k == 0) {
        return head;
    }

    old_tail->next = head;

    struct ListNode* newTail = head;
    for(int i = 0; i < len-k-1; i++) {
        newTail = newTail->next;
    }
    struct ListNode* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}
// @lc code=end

