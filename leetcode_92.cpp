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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right){
            return head;
        }
        int pos = 0;
        int left_val=0;
        ListNode* tmp_lst = new ListNode(0,head);
        ListNode* reverse_lst = tmp_lst;
        ListNode* result = tmp_lst;
        vector<int> rev_vec;
        for(pos=1;pos<=right;pos++){
            reverse_lst = reverse_lst->next;
            if(pos>=left){
                rev_vec.push_back(reverse_lst->val);
            }
        }
        for(pos = 1; pos <= right ; pos++){
            tmp_lst = tmp_lst->next;
            if(pos>=left){
                tmp_lst->val = rev_vec.back();
                rev_vec.pop_back();
            }
        }

        return result->next;
    }
};


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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right && head==NULL){
            return head;
        }
        int pos = 0;
        ListNode* cur = head;
        ListNode* pre = NULL;
        ListNode* third;

        while(left>1){
            pre = cur;
            cur = cur->next;
            left--;
            right--;
        }
        ListNode *con=pre, *tail = cur;

        while(right>0){
            third = cur->next;
            cur->next = pre;
            pre = cur;
            cur = third;
            right--;
        }
        if(con!=NULL){
            con->next = pre;
        }else{
            head = pre;
        }

        tail->next = cur;

        return head;
    }
};
