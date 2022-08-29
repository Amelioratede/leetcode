#include<bits/stdc++.h>
using namespace std;

///////////////// ( () () ((((())))) ) ==> 0 1 1 2^(N-1) ) => 2*(2+2^(N-1))
////////////////Solution using stack
///////////////
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> mstk;
        int score = 0;

        for(auto c:s){
            if(c=='('){
                mstk.push(score);
                score = 0;
            }
            else{
                score=mstk.top()+max(2*score,1);
                mstk.pop();
            }
        }
        return score;
    }
};
////////////////Solution using divide and conquer
///////////////Java
class Solution {

    public int scoreOfParentheses(String S) {
        return F(S, 0, S.length());
    }

    public int F(String S, int i, int j) {
        //Score of balanced string S[i:j]
        int ans = 0, bal = 0;

        // Split string into primitives
        for (int k = i; k < j; ++k) {
            bal += S.charAt(k) == '(' ? 1 : -1;
            if (bal == 0) {
                if (k - i == 1) ans++;
                else ans += 2 * F(S, i+1, k);
                i = k+1;
            }
        }

        return ans;
    }
}

////////////Optimizing divide and conquer(balanced!!!!!)
////////////java version
//////////////这种数学转化是真的很巧
class Solution {

    public int scoreOfParentheses(String S) {
        int ans = 0, bal = 0;
        for (int i = 0; i < S.length(); ++i) {
            if (S.charAt(i) == '(') {
                bal++;
            } else {
                bal--;
                if (S.charAt(i-1) == '(')
                    ans += 1 << bal;
            }
        }

        return ans;
    }
}
