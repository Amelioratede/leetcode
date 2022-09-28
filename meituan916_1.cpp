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

int solve(int n,vector<int> v,int way){
    int res =0;
    priority_queue<int> pq;

    for(int i=way==1?0:n-1;i<v.size()&&i>=0;i+=way){
        if(!pq.empty()){
            if(pq.top()>v.size()){
                int temp = pq.top()-v[i];
                res+=temp;
                pq.top();
            }
        }
        pq.push(v[i]);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n,0);
    FOR(i,n){
        cin >> v[i];
    }
    cout << min(solve(n,v,1),solve(n,v,-1)) << endl;
    return 0;
}





























void anything(){

}
