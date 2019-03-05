// Source : https://leetcode.com/problems/reverse-nodes-in-k-group/
// Author : nanguoyu
// Date   : 2019/3/5

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseKGroup(struct ListNode *head, int k)
{
#define nullptr 0;
    if (!head) {
        return nullptr;
    }
    struct ListNode *result = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *last = nullptr,*node, *endNode, *start;
    result->next = last;
    struct ListNode *iPtr = head;
    int number = 0;
    while (iPtr) {iPtr = iPtr->next;number++;}

    int j = number / k, m = number % k;

    for (int i = 0; i < j; ++i) {
        start = head;node = head;endNode = head;

        for (int l = 0; l < k; ++l) {
            head = head->next;
            if (l == 0) { endNode = start; } else { start->next = node; }
            node = start;
            start = head;
        }
        if (!result->next) { result->next = node; } else { last->next = node; }
        endNode->next = head;
        last = endNode;
    }
    if (head) {
        node = head;
        if (!result->next) { result->next = node; } else { last->next = node; }
    }

    return result->next;
}