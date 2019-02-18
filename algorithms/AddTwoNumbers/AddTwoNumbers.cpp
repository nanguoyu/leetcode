// Source : https://oj.leetcode.com/problems/add-two-numbers/
// Author : nanguoyu
// Date   : 2019-02-18
/**********************************************************************************
*
* You are given two linked lists representing two non-negative numbers.
* The digits are stored in reverse order and each of their nodes contain a single digit.
* Add the two numbers and return it as a linked list.
*
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
*
**********************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
       struct ListNode* NumberSum = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode* w = NumberSum;
    int singleDigits=0, carry=0;
    struct ListNode* p =l1;
    struct ListNode* q =l2;
    while(p&&q){
        struct ListNode *t = (struct ListNode *)malloc(sizeof(struct ListNode));
        singleDigits = (p->val+q->val+carry)%10;
        t->val = singleDigits;
        carry = (p->val+q->val+carry)/10;
        w->next =t;
        w=t;
        p=p->next;
        q=q->next;

    }
    if(p&&!q){
        while(p){
            struct ListNode *t = (struct ListNode *)malloc(sizeof(struct ListNode));
            t->val = (p->val+carry)%10;
            carry = (p->val+carry)/10;
            w->next =t;
            w=t;
            p=p->next;
        }
    }
    else if(!p&&q){
        while(q){
            struct ListNode *t = (struct ListNode *)malloc(sizeof(struct ListNode));
            t->val = (q->val+carry)%10;
            carry = (q->val+carry)/10;
            w->next =t;
            w=t;
            q=q->next;
        }
    }
    if(carry){
        struct ListNode *t = (struct ListNode *)malloc(sizeof(struct ListNode));
        t->val = carry;
        w->next =t;
        w=t;
    }
    w->next=NULL;
    return NumberSum->next;
}
