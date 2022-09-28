#include<bits/stdc++.h>
using namespace std;

// #pragma GCC optimize("Ofast")
// #pragma GCC optimization("unroll-loops, no-stack-protector")
typedef long long LL;
typedef pair<LL, LL> PL;
typedef vector<LL> VL;
typedef vector<PL> VPL;
typedef vector<VL> VVL;

typedef pair<int, int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;
typedef vector<vector<int>> VVI;
typedef vector<vector<PI>> VVPI;

typedef long double LD;
typedef pair<LD, LD> PLDLD;

typedef complex<double> CD;
typedef vector<CD> VCD;

#define MP make_pair
#define PB push_back
#define F first
#define S second
#define LB lower_bound
#define UB upper_bound

#define SZ(x) ((int)x.size())
#define LEN(x) ((int)x.length())
#define ALL(x) begin(x), end(x)
#define RSZ resize
#define ASS assign
#define REV(x) reverse(x.begin(), x.end());

#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define FOR(i, n) for (int i = 0; i < n; i++)
#define FOR1(i, n) for (int i = 1; i <= n; i++)
#define SORT(x) sort(x.begin(), x.end())
#define RSORT(x) sort(x.rbegin(), x.rend())
#define SUM(x) std::accumulate(x.begin(), x.end(), 0LL)

#define IN(x) cin >> x;
#define OUT(x) cout << x << "\n";
#define INV(x, n) FOR(iiii, n) { cin >> x[iiii]; }
#define INV1(x, n) FOR1(iiii, n) { cin >> x[iiii]; }
#define OUTV(x, n) { FOR(iiii, n) { cout << x[iiii] << " "; } cout << "\n"; }
#define OUTV1(x, n) { FOR1(iiii, n) { cout << x[iiii] << " "; } cout << "\n"; }
#define OUTYN(x) { if (x) cout << "YES\n"; else cout << "NO\n"; }
#define OUTyn(x) { if (x) cout << "Yes\n"; else cout << "No\n"; }

const LL INF = 1E18;
const int MAXX = 200005;
const LD PAI = 4 * atan((LD)1);

#define MOD7 1000000007
#define MOD9 1000000009
#define MOD3 998244353
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl

void helper(vector<int>& dp,int a,int JB,int cur_day,int left_s,vector<int> V, int& max_val){
    if(JB==0&&cur_day<dp.size()){
        dp[cur_day]=dp[cur_day-1]+V[cur_day-1]-a;
        cout << "No JB" << endl;
        cout << cur_day << " " << dp[cur_day] << " "<< left_s << endl;
        if(dp[cur_day]>=left_s){
            max_val = max(max_val,left_s);
            return;
        }
        helper(dp,a,0,cur_day+1,left_s-a,V,max_val);
        helper(dp,a,1,cur_day+1,left_s-2*a,V,max_val);
    }else if(JB==1&&cur_day<dp.size()){
        dp[cur_day]=dp[cur_day-1]+2*V[cur_day-1]-2*a;
        cout << "JB" << endl;
        cout << cur_day << " " << dp[cur_day] << " "<< left_s << endl;
        if(dp[cur_day]>=left_s){
            max_val = max(max_val,left_s);
            return;
        }
        helper(dp,a,0,cur_day+1,left_s-a,V,max_val);
    }
    return ;

}

int main()
{
    int S=2000,n=5,a=10;
    vector<int> dp(n+1,INT_MIN);
    vector<int> V={200,400,500,300,100};
    dp[0]=0;

    int max_val=-1;
    helper(dp,a,0,1,S-a,V,max_val);
    helper(dp,a,1,1,S-2*a,V,max_val);

    cout << max_val << endl;

    return 0;

}





























void anything(){

}
