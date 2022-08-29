/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int intercept = 0;
        ListNode* tmp = new ListNode(0,l1);
        ListNode* pos = tmp;
        int result = 0;

        if(l1==NULL and l2==NULL){
            return l1;
        }else if(l1==NULL){
            return l2;
        }else if(l2==NULL){
            return l1;
        }

        while(l1 && l2){
            result = l1->val + l2->val + intercept;
            tmp->next->val = result%10;
            intercept = result/10;
            tmp = tmp->next;
            l1 = l1->next;
            l2 = l2->next;
        }


        if(!l1 and !l2){

            if(intercept!=0){
                tmp->next = new ListNode(intercept);
            }else{
                tmp->next = NULL;
            }
        }else{
            while(l1){
                result = l1->val + intercept;
                tmp->next->val = result%10;
                intercept = result/10;
                tmp = tmp->next;
                l1 = l1->next;
                if(intercept!=0 && !l1){
                    tmp->next = new ListNode(intercept);
                }
            }
            while(l2){
                result = l2->val + intercept;
                tmp->next = l2;
                tmp->next->val = result%10;
                intercept = result/10;
                tmp = tmp->next;
                l2 = l2->next;
                if(intercept!=0 && !l2){
                    tmp->next = new ListNode(intercept);
                }
            }
        }

        return pos->next;
    }
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int c = 0;
    ListNode newHead(0);
    ListNode *t = &newHead;
    while(c || l1 || l2) {
        c += (l1? l1->val : 0) + (l2? l2->val : 0);
        t->next = new ListNode(c%10);
        t = t->next;
        c /= 10;
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }
    return newHead.next;
}
