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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 or !head)
            return head;

        ListNode* new_head = new ListNode(-1);
        ListNode* last_node = head;

        int List_size = 1;
        while(last_node->next){
            List_size++;
            last_node = last_node->next;
        }

        ListNode* curr = head;
        k = k%List_size;
        int step = List_size - k;
        if(k==0)
            return head;

        while(step!=1){
            curr = curr->next;
            step--;
        }

        new_head->next = curr->next;
        curr->next = NULL;
        last_node->next = head;


        return new_head->next;
    }
};
