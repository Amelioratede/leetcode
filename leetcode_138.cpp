#include<bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};



Node* copyRandomList(Node* head) {
        Node* rec_head = head;

        vector<Node> N_lst = {};
        int pos = 0;
        //Setting new nodes' value and .next pointer
        while(head){
            N_lst.push_back(Node(head->val));
            head->val = pos;
            cout << head->val << endl;

            head = head->next;
            if(pos>=1){
                N_lst[pos-1].next = &N_lst[pos];
            }
            if(!head)
                N_lst[pos].next = NULL;

            pos++;
        }
        pos = 0;
        //Setting new nodes.random pointer
        while(rec_head){

            if(rec_head->random){
                cout << rec_head->random->val << endl;
                N_lst[pos].random = &N_lst[rec_head->random->val];
            }else{
                cout << pos << endl;
                N_lst[pos].random = N_lst[N_lst.size()-1].next;
            }
            rec_head = rec_head->next;
            pos++;
        }
        for(auto n : N_lst){
            cout << n.val << endl;
            if(n.next){
                cout << "next==" << n.next->val << endl;
            }
            if(n.random){
                cout << "random==" << n.random->val << endl;
            }
        }

        return &(N_lst[0]);
}

int main(int argc, char const *argv[]) {
    Node head(7);
    Node head_1(13);
    Node head_2(11);
    Node head_3(10);
    Node head_4(1);

    head.next = &head_1;
    head_1.next = &head_2;
    head_2.next = &head_3;
    head_3.next = &head_4;
    head_4.next = NULL;

    head.random = head_4.next;
    head_1.random = &head;
    head_2.random = &head_4;
    head_3.random = &head_2;
    head_4.random = &head;



    Node* res = copyRandomList(&head);
    // while(res){
    //     cout<< res->val << endl;
    //     res = res->next;
    // }
    return 0;
}

////////////////////// 区别在于Node*的运用！！！！！！！！
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* rec_head = head;
        if(!head)
            return NULL;

        vector<Node*> N_lst;
        int pos = 0;
        //Setting new nodes' value and .next pointer
        while(head){
            N_lst.push_back(new Node(head->val));
            head->val = pos;
            cout << head->val << endl;

            head = head->next;
            if(pos>=1){
                N_lst[pos-1]->next = N_lst[pos];
            }
            if(!head)
                N_lst[pos]->next = NULL;

            pos++;
        }
        pos = 0;
        //Setting new nodes.random pointer
        while(rec_head){

            if(rec_head->random){
                cout << rec_head->random->val << endl;
                N_lst[pos]->random = N_lst[rec_head->random->val];
            }else{
                cout << pos << endl;
                N_lst[pos]->random = N_lst[N_lst.size()-1]->next;
            }
            rec_head = rec_head->next;
            pos++;
        }

        return N_lst[0];
}
};


//////////////////////////////////////////////////////
///映射关系问题可以使用map解决
class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> m;
        int i=0;
        Node* ptr = head;
        while (ptr) {
            m[ptr] =new Node(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        while (ptr) {
            m[ptr]->next = m[ptr->next];
            m[ptr]->random = m[ptr->random];
            ptr = ptr->next;
        }
        return m[head];
    }
};
