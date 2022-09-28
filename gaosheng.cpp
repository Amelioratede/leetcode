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
    string  s = "010110";
    int res = 0;
    int first_0=INT_MAX,first_1=INT_MAX,last_0=INT_MAX,last_1=INT_MAX;
    int ff_0=INT_MAX,ff_1=INT_MAX,ll_0=INT_MAX,ll_1=INT_MAX;
    // vector<int> bo={0,0};
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            first_0=min(first_0,i);
            last_0=i;
        }
        if(s[i]=='1'){
            first_1=min(first_1,i);
            last_1=i;
        }
    }
    //  0-----0
    if(last_0-first_0>=4&&last_0!=INT_MAX){
        for(int i=first_0+1;i<last_0;i++){
            if(s[i]=='0'){
                ff_0=min(ff_0,i);
                ll_0=i;
            }else{
                ff_1=min(ff_1,i);
                ll_1=i;
            }
        }

        cout << "you are here!" << endl;
        cout << ff_0 << " " << ll_0 << " " << ff_1 << " " << ll_1 << endl;
        if(ll_0-ff_0>=2&&ll_0!=INT_MAX){
            // for(int i=ff_0+1;i<ll_0;i++){
            //     cout << "inside the inner space" << endl;
            //     if(bo[s[i]-'0']==0){
            //         cout << "00 res + 1" << endl;
            //         res++;
            //         bo[s[i]-'0']=1;
            //     }
            // }
            cout << "inside the inner space" << endl;
            cout << "00 res +" << endl;
            res+=ll_0-ff_0-1;

        }
        if(ll_1-ff_1>=2&&ll_1!=INT_MAX){
            cout << "inside the inner space" << endl;
            cout << "11 res +" << endl;
            res+=ll_1-ff_1-1;
        }
    }

    //  1-----1
    if(last_1-first_1>=4&&last_1!=INT_MAX){
        ff_0=INT_MAX,ff_1=INT_MAX,ll_0=INT_MAX,ll_1=INT_MAX;
        for(int i=first_1+1;i<last_1;i++){
            if(s[i]=='0'){
                ff_0=min(ff_0,i);
                ll_0=i;
            }else{
                ff_1=min(ff_1,i);
                ll_1=i;
            }
        }

        cout << "you are here!" << endl;
        cout << ff_0 << " " << ll_0 << " " << ff_1 << " " << ll_1 << endl;
        if(ll_0-ff_0>=2&&ll_0!=INT_MAX){
            // for(int i=ff_0+1;i<ll_0;i++){
            //     cout << "inside the inner space" << endl;
            //     if(bo[s[i]-'0']==0){
            //         cout << "00 res + 1" << endl;
            //         res++;
            //         bo[s[i]-'0']=1;
            //     }
            // }
            cout << "inside the inner space" << endl;
            cout << "00 res +" << endl;
            res+=ll_0-ff_0-1;

        }
        if(ll_1-ff_1>=2&&ll_1!=INT_MAX){
            cout << "inside the inner space" << endl;
            cout << "11 res +" << endl;
            res+=ll_1-ff_1-1;
        }
    }
    cout << res << endl;

}





























void anything(){

}
