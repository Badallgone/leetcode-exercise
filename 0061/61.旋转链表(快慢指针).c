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
    int len = 0;
    struct ListNode* tmp = head;
    while(tmp) {
        len++;
        tmp = tmp->next;
    }
    if(len == 0) {
        return head;
    }
    k = k % len;
    if(k == 0) {
        return head;
    }

    struct ListNode* fast = head;
    struct ListNode* slow = head;
    for(int i = 0; i < k; i++) {
        fast = fast->next;
    }
    while(fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    struct ListNode* newHead = slow->next;
    slow->next = NULL;
    fast->next = head;
    return newHead;
}
// @lc code=end

