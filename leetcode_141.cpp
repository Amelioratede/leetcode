#include<bits/stdc++.h>
using namespace std;

/**
 Definition for singly-linked list.
**/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        while(head->val != 1000000)
        {
            if(head->next == NULL){
               return false;
            }
            head->val = 1000000;
            head = head->next;
        }
        return true;
    }
};
