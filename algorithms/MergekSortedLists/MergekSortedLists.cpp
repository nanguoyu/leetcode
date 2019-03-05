// Source : https://leetcode.com/problems/merge-k-sorted-lists/
// Author : nanguoyu
// Date   : 2019/3/4

/************************************************************************************************
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
1->4->5,
1->3->4,
2->6
]
Output: 1->1->2->3->4->4->5->6
 *************************************************************************************************/

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize)
{
#define nullptr 0;
    struct ListNode *result = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *last;
    last = nullptr;
    result->next = last;
    int i = 0, w = 0;
    for (int k = 0; k < listsSize; ++k) {
        if (lists[k]) {
            i++;
            w = k;
        }
    }

    if (i == 0 || i == 1 || listsSize == 0) {
        return lists[w];
    }

    while (i > 1) {
        int j = 0;
        int x = 0;
        bool spool = false;
        for (j = 0, i = 0; j < listsSize; ++j) {
            if (!lists[j]) continue;
            if (!spool) {
                spool = true;
                x = j;
            }
            if (lists[j]->val <= lists[x]->val) {
                x = j;
            }
            i++;

        }

        if (!result->next) {
            last = lists[x];
            result->next = lists[x];
            lists[x] = lists[x]->next;
        } else {
            last->next = lists[x];
            last = lists[x];
            lists[x] = lists[x]->next;
        }

    }
    return result->next;

}