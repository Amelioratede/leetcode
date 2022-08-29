#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
   if(s.empty())
       return true;

   int tmp[s.size()];
   int i = 0;
   int sum = 0;
   for(auto c : s){
       switch(c){
           case '(':
               tmp[i] = 1;
               break;
           case '[':
               tmp[i] = 2;
               break;
           case '{':
               tmp[i] = 3;
               break;
           case ')':
               tmp[i] = -1;
               break;
           case ']':
               tmp[i] = -2;
               break;
           case '}':
               tmp[i] = -3;
               break;

       }
       sum += tmp[i];
       i++;
   }

   if(sum!=0)
       return false;

   int chk_sum = 0;
   int pos_tmp = 0;


   i = 0;
   while(pos_tmp<s.size()){
       cout << "i=" << i << endl;
       cout << "pos_tmp=" << pos_tmp << endl;
       for(int j=pos_tmp;j<s.size();j++){
           if(tmp[j]<0){
               if(j>pos_tmp){
                   i = j-1;
                   break;
               }else{
                   return false;
               }
           }
       }
       cout << "i=" << i << endl;
       cout << "pos_tmp=" << pos_tmp << endl;
       chk_sum = 0;
       for(int k=1 ; k<=(i-pos_tmp+1) ; k++){
           if((i+k)>=s.size()){
               return false;
           }
           chk_sum += tmp[i+k]+tmp[i-k+1];
           cout << "cheak sum=" << chk_sum << endl;
           if(chk_sum!=0){
               return false;
           }
       }
       i = 2*i-pos_tmp+1;
       pos_tmp = i+1;
   }
   return true;
}

int main(int argc, char const *argv[])
{
    string s = "(}{)";
    isValid(s);
    return 0;
}

////////////////////巨蠢的一种写法

////////////////////使用栈stack就搞定了

bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mp = {{'(', ')'}, {'{', '}'}, {'[', ']'}};

        for(char c: s) {
            if(mp.find(c) != mp.end()) {
                st.push(c);
            } else if(!st.empty() && mp[st.top()] == c) {
                    st.pop();
            } else {
                return false;
            }
        }

        return st.empty();
    }
//////////////////////////////这里有关于map的使用方法

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  //taking stack for keep tracking the order of the brackets..
        for(auto i:s)  //iterate over each and every elements
        {
            if(i=='(' or i=='{' or i=='[') st.push(i);  //if current element of the string will be opening bracket then we will just simply push it into the stack
            else  //if control comes to else part, it means that current element is a closing bracket, so check two conditions  current element matches with top of the stack and the stack must not be empty...
            {
                if(st.empty() or (st.top()=='(' and i!=')') or (st.top()=='{' and i!='}') or (st.top()=='[' and i!=']')) return false;
                st.pop();  //if control reaches to that line, it means we have got the right pair of brackets, so just pop it.
            }
        }
        return st.empty();  //at last, it may possible that we left something into the stack unpair so return checking stack is empty or not..
    }
};

////////////////////////////

class Solution {
public:
bool isValid(string s) {
    if(s.empty())
        return true;

    stack<char> par_stack;

    for(auto c:s){
        if(c=='(' or c=='[' or c=='{')
            par_stack.push(c);
        if(c==')' or c==']' or c=='}'){
            if(par_stack.empty())
                return false;
            if(c==')' and par_stack.top()!='(')
                return false;
            else if(c==']' and par_stack.top()!='[')
                return false;
            else if(c=='}' and par_stack.top()!='{')
                return false;
            else
                par_stack.pop();

        }
    }
    if(!par_stack.empty())
        return false;


    return true;
    }

};
