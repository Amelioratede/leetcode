#include<bits/stdc++.h>
#include<stack>
using namespace std;

string minRemoveToMakeValid(string s) {
    stack<char> my_stack;
    stack<char> res_stack_l;
    stack<char> res_stack_r;
    for(char c : s){
        if(c=='('){
            cout << "here_1" << endl;
            my_stack.push(c);
        }else if(c==')'){
            cout << "here_2" << endl;
            if(!my_stack.empty() && my_stack.top()=='('){
                res_stack_l.push('(');
                res_stack_r.push(c);
                my_stack.pop();
            }
        }else{}
    }
    cout << "here" << endl;
    string res_s="";
    for(auto c1:s){
        if(c1=='('){
            if(!res_stack_l.empty()){
                res_s+=c1;
                res_stack_l.pop();
            }
        }else if(c1==')'){
            if(!res_stack_r.empty() && res_stack_l.size()<res_stack_r.size()){
                res_s+=c1;
                res_stack_r.pop();
            }
        }else{
            res_s+=c1;
        }

    }
    cout<<res_s<<endl;

    return res_s;
}

int main()
{
    string s = "lee(t(c)o)de)";
    minRemoveToMakeValid(s);
    return 0;
}

/////////////////////////////////
class Solution {
public:
    string minRemoveToMakeValid(string s) {

        stack<int>st; // helper stack for finding matching parentheses

        for(int i=0;i<s.length();++i){
            if(s[i]=='('){ // for open parentheses push into stack
                st.push(i);
            }
            else if(s[i]==')'){ // for closing parentheses
                // if no matching previous open parentheses found, we need to remove the index of that open parentheses from "s" so for now we are marking it with special character '#'
                if(st.empty()){
                    s[i]='#';
                }
                else{
                    // if matching open parentheses found remove that from the stack
                    st.pop();
                }
            }
        }

        // if stack is not empty, that means it contains open parentheses indexes which don't have any matching closing parentheses
        while(!st.empty()){
            s[st.top()]='#';
            st.pop();
        }

        string ans="";
        for(int i=0;i<s.length();++i){
            if(s[i]!='#'){ // append not marked character to the end of "ans"
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};

//Using stack<int> to keep check for pos！！！！！！！！！！！
//Time: O(n)  Space:O(n)
//////////////////////////////////////////////////
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        // Step 1 : Iterate from start
        int count=0;
        for(int i=0;i<n;++i){
            if(s[i]=='('){ // for open bracket
                ++count;
            }
            else if(s[i]==')'){ // for close bracket
                if(count==0){  // if no. of close brackets > no. of open brackets
                    s[i]='#';
                }
                else{
                    // if matching parentheses found decrease count
                    --count;
                }
            }
        }

        // Step 2 : Iterate from end
        count=0;
        for(int i=n-1;i>=0;--i){
            if(s[i]==')'){ // for close bracket
                ++count;
            }
            else if(s[i]=='('){ // for open bracket
                if(count==0){ // if no. of open brackets > no. of close brackets
                    s[i]='#';
                }
                else{
                    // if matching parentheses found decrease count
                    --count;
                }
            }
        }

        // Step 3 : Create "ans" by ignoring the special characters '#'
        string ans="";
        for(int i=0;i<n;++i){
            if(s[i]!='#'){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
//////////////////// Time: O(3n) Space: O(1)
