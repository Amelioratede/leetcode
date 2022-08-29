#include <bits/stdc++.h>
using namespace std;

// Driver code
int main ()
{
    // Creates a min heap
    priority_queue <int, vector<int>, greater<int> > pq;
    pq.push(5);
    pq.push(1);
    pq.push(10);
    pq.push(30);
    pq.push(20);

    // One by one extract items from min heap
    while (pq.empty() == false)
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty() || !lists.back()){
            return NULL;
        }

        ListNode* result = new ListNode(-1);
        ListNode* head = result;

        int min_val = 100000;
        int len = lists.size();
        if(len==1)
            return lists.back();

        ListNode* L[len];
        int min_pos = 0;


        //set end_loop condition
        int j = 0;
        bool end_loop = true;

        //setup for further usage
        map<int,int> tmp_i;
        priority_queue <int, vector<int>, greater<int> > pq;
        int i=0;
        for (std::vector<ListNode*>::iterator it = lists.begin(); it != lists.end(); ++it,++i){
            if(j<len){
                L[i] = *it;
                j++;
            }
            if(!L[i])
                continue;
            int tmp = L[i]->val;
            tmp_i[tmp] = i;
            pq.push(tmp);
        }

        int mj=0;
        while(mj<5){
            end_loop = true;
            for(int i=0; i<len ; i++){
                if(L[i]){
                    end_loop = false;
                    break;
                }
            }
            if(end_loop)
                break;

            //using min heap to store values and using map to get the corresponding ListNode
            min_pos = tmp_i[pq.top()];
            pq.pop();
            result->next = L[min_pos];
            L[min_pos] = L[min_pos]->next;
            result = result->next;
            //check if we need to end the loop

            if(L[min_pos]){
                pq.push(L[min_pos]->val);
                tmp_i[L[min_pos]->val] = min_pos;
            }
            mj++;

        }
        result->next = NULL;

        return head->next;

    }
};
