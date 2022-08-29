#include<bits/stdc++.h>
using namespace std;

int climbStairs(int n) {
    vector<int> dp(n+1,0);
    if(n==0)
        return 0;
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    if(n>2){

        for(int i=3; i<=n ;i++){
           dp[i]=dp[i-1]+dp[i-2];
       }
    }
    return dp[n];
}

int main(int argc, char const *argv[]) {
    int res = climbStairs(4);
    cout << res << endl;

    return 0;
}
