// Source : https://leetcode.com/problems/merge-two-sorted-lists/
// Author : nanguoyu
// Date   : 2019/3/3


/*
Merge two sorted linked lists and return it as a new list. The new list should be made by
splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
 */


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
#define nullptr 0;
    struct ListNode *result = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *last;
    last = nullptr;
    result->next = last;
    result->val = 0;

    while (l1 && l2) {
        if (l1->val <= l2->val) {
            if (!result->next) {
                result->next = l1;
                last = l1;
                l1 = l1->next;
            } else {
                last->next = l1;
                last = l1;
                l1 = l1->next;
            }
        } else {
            if (!result->next) {
                result->next = l2;
                last = l2;
                l2 = l2->next;
            } else {
                last->next = l2;
                last = l2;
                l2 = l2->next;
            }

        }
    }
    if (!l1 && l2) {
        if (last) {
            last->next = l2;
        } else {
            return l2;
        }
    } else if (l1) {
        if (last) {
            last->next = l1;
        } else {
            return l1;
        }
    }

    return result->next;
}