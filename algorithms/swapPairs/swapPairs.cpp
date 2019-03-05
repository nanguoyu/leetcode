// Source : https://leetcode.com/problems/swap-nodes-in-pairs/
// Author : nanguoyu
// Date   : 2019/3/5
//

//Given a linked list, swap every two adjacent nodes and return its head.
//
//You may not modify the values in the list's nodes, only nodes itself may be changed.
//
//
//
//Example:
//
//Given 1->2->3->4, you should return the list as 2->1->4->3.


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head)
{
#define nullptr 0;
    struct ListNode *result = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *last;
    last = nullptr;
    result->next = last;

    struct ListNode *remain;
    if(head && !head->next){
        return head;
    }
    while (head && head->next) {
        if (!result->next) {
            result->next = head->next;
            remain = head->next->next;
            head->next->next = head;
            head->next = remain;
            last=head;
            head = remain;
        } else {
            last->next = head->next;
            remain = head->next->next;
            head->next->next = head;
            head->next = remain;
            last=head;
            head = remain;
        }

    }


    return result->next;


}
