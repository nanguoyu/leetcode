// Source : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Author : nanguoyu
// Date   : 2019/3/2

//Given a linked list, remove the n-th node from the end of list and return its head.
//
//Example:
//
//Given linked list: 1->2->3->4->5, and n = 2.
//
//After removing the second node from the end, the linked list becomes 1->2->3->5.
//Note:
//
//Given n will always be valid.
//
//Follow up:
//

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode** Listbuffer = (struct ListNode**)malloc(sizeof(struct ListNode**)*1000);
    int i=0;
    struct ListNode* p =head;
    while(p->next){
        Listbuffer[i]=p;
        i++;
        p=p->next;
    }
    if(n>i+1||(n==1&&i==0)){
        return 0;
    }
    if (n==i+1){
        head=head->next;
        return head;
    }
    if(n==0){
        return head;
    }else if(n==1){
        Listbuffer[i-n]->next=NULL;
        return head;
    }else{
        Listbuffer[i-n]->next=Listbuffer[i-n+1]->next;
        return head;
    }
}