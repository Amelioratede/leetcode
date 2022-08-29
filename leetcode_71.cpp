#include<bits/stdc++.h>
using namespace std;

string simplifyPath(string path) {
    path+="/";
    stack<string> my_stk;
    string res="";

    string tmp_str="";
    for(auto ch : path){
        if(ch=='/'){
            if(tmp_str=="" or tmp_str=="."){}
            else if(tmp_str==".."){
                if(!my_stk.empty()){
                    cout << "top"<<my_stk.top() << endl;
                    my_stk.pop();
                }
            }else{
                cout << tmp_str << endl;
                my_stk.push(tmp_str);
            }
            tmp_str="";
        }
        else{
            tmp_str += ch;
        }
    }

    while(!my_stk.empty()){
            res = "/"+my_stk.top()+res;
            cout << res << endl;
            my_stk.pop();
        }
    if(res=="")
        return "/";
    return res;
}

int main(){
    simplifyPath("/a//b////c/d//././/..");

    return 0;
}
