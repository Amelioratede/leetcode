#include<bits/stdc++.h>
using namespace std;

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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *my_lst_nde = new ListNode(0,head);
        if(!head)
            return head;
        int old_val=head->val;
        bool repetitive=false;
        ListNode *ptn = my_lst_nde;
        int size = 0;


        while(head->next){
            int new_val = head->next->val;
            if(old_val!=new_val && !repetitive){
                my_lst_nde->next = head;
                my_lst_nde = my_lst_nde->next;
            }
            else if(old_val!=new_val && repetitive){
                repetitive = false;
            }
            else{
                repetitive = true;
            }
            old_val = new_val;
            head = head->next;
        }
        if(!repetitive){
            my_lst_nde->next = head;
        }else{
            my_lst_nde->next = head->next;
        }


        return ptn->next;

    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return head;
        // 链表头也可能删除，所以用dummy node进行辅助
        ListNode dummy(0);
        dummy.next = head;
        head = &dummy;
        while (head->next && head->next->next)
        {
            if (head->next->val == head->next->next->val)
            {
                int rmVal = head->next->val;
                while (head->next && head->next->val == rmVal)
                {
                    ListNode* rmNode = head->next;
                    head->next = head->next->next;
                    delete rmNode;
                }
            }
            else
                head = head->next;
        }
        return dummy.next;
    }
};
