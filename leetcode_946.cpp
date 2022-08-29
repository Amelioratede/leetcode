#include<bits/stdc++.h>
using namespace std;

class Solution_1 {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s ;   // an empty stack
        int j = 0;
        for(int i= 0; i<pushed.size(); ++i)
        {
            s.push(pushed[i]);

			// check if pushed values is next to pe popped out.
            while(!s.empty() && s.top() == popped[j])
            {
                s.pop();
                ++j;
            }
        }
		// if stack is empty means sequence is correct.
        return s.empty();
    }
};

// If the element X has been pushed to the stack then check if the top element in the pop[] sequence is X or not.
// If it is X then pop it right now else top of the push[] sequence will be changed and make the sequences invalid.
// similarly, do the same for all the elements and check if the stack is empty or not in the last.
// If empty then return True else return False.
// Time Complexity O(N)
// Space Complexity O(N)


// 😉😉😉😉Please upvote if it helps 😉😉😉😉
class Solution_2 {
    public:
        bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
            int i = 0, j = 0;
            for(int x :  pushed)
            {
            pushed[i++] = x;
            // check that current pushed element matches with popped sequence
            while(i> 0 && pushed[i-1] == popped[j])
            {
            --i;
            ++j;
            }
            }
            // as pushed is a permutation of stack so at end it should be empty
            return i == 0;
            }
};

// Using pushed vector as a stack.
// Same Steps as above approach.
// As both pushed and popped are permutation of each other.
// At end the vector will be empty if sequence is correct.
// TIME COMPLEXITY O(n)
// SPACE COMPLEXITY O(1)
// Though In second approach for achieveing space complexity of O(1), i am modifying inputs, of which i am not in favour.

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        bool is_stack = true;
        map<int, int> my_map;
        stack<int> check_stack;

        for(int i=0; i<pushed.size(); i++){
            my_map[pushed[i]] = i;
        }


        int tmp=-1;
        for(int i=0; i<popped.size(); i++){
            int pop_tmp = my_map[popped[i]];
            if(pop_tmp>tmp){
                for(int i=tmp+1; i<pop_tmp+1; i++){
                    check_stack.push(pushed[i]);
                }
                tmp = pop_tmp;
                check_stack.pop();

            }else{
                if(check_stack.top()!=popped[i]){
                    is_stack=false;
                }
                else{
                    check_stack.pop();
                }
            }


        }
        return is_stack;
    }
};
