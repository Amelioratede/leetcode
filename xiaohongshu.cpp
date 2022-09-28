// #include<bits/stdc++.h>
// using namespace std;
//
// // #pragma GCC optimize("Ofast")
// // #pragma GCC optimization("unroll-loops, no-stack-protector")
// typedef long long LL;
// typedef pair<LL, LL> PL;
// typedef vector<LL> VL;
// typedef vector<PL> VPL;
// typedef vector<VL> VVL;
//
// typedef pair<int, int> PI;
// typedef vector<int> VI;
// typedef vector<PI> VPI;
// typedef vector<vector<int>> VVI;
// typedef vector<vector<PI>> VVPI;
//
// typedef long double LD;
// typedef pair<LD, LD> PLDLD;
//
// typedef complex<double> CD;
// typedef vector<CD> VCD;
//
// #define MP make_pair
// #define PB push_back
// #define F first
// #define S second
// #define LB lower_bound
// #define UB upper_bound
//
// #define SZ(x) ((int)x.size())
// #define LEN(x) ((int)x.length())
// #define ALL(x) begin(x), end(x)
// #define RSZ resize
// #define ASS assign
// #define REV(x) reverse(x.begin(), x.end());
//
// #define MAX(x) *max_element(ALL(x))
// #define MIN(x) *min_element(ALL(x))
// #define FOR(i, n) for (int i = 0; i < n; i++)
// #define FOR1(i, n) for (int i = 1; i <= n; i++)
// #define SORT(x) sort(x.begin(), x.end())
// #define RSORT(x) sort(x.rbegin(), x.rend())
// #define SUM(x) std::accumulate(x.begin(), x.end(), 0LL)
//
// #define IN(x) cin >> x;
// #define OUT(x) cout << x << "\n";
// #define INV(x, n) FOR(iiii, n) { cin >> x[iiii]; }
// #define INV1(x, n) FOR1(iiii, n) { cin >> x[iiii]; }
// #define OUTV(x, n) { FOR(iiii, n) { cout << x[iiii] << " "; } cout << "\n"; }
// #define OUTV1(x, n) { FOR1(iiii, n) { cout << x[iiii] << " "; } cout << "\n"; }
// #define OUTYN(x) { if (x) cout << "YES\n"; else cout << "NO\n"; }
// #define OUTyn(x) { if (x) cout << "Yes\n"; else cout << "No\n"; }
//
// const LL INF = 1E18;
// const int MAXX = 200005;
// const LD PAI = 4 * atan((LD)1);
//
// #define MOD7 1000000007
// #define MOD9 1000000009
// #define MOD3 998244353
// #define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
// #define out(x,y) cout << ">> " << (x) << " " << (y) << endl
//
//
// int main()
// {
//     cout << "you are in" << endl;
//     vector<int> a(4,0);
//     FOR(i,4){
//         cin >> a[0];
//     }
//     int x;
//     cin >> x;
//     vector<int> a1(a[0],0);
//     vector<int> a2(a[1],0);
//     vector<int> a3(a[2],0);
//     vector<int> a4(a[3],0);
//     INV(a1,a[0]);
//     INV(a2,a[1]);
//     INV(a3,a[2]);
//     INV(a4,a[3]);
//
//     int res = INT_MAX;
//     res = min(res,(int)(a1.end()-upper_bound(a1.begin(),a1.end(),x)));
//     res = min(res,(int)(a2.end()-upper_bound(a2.begin(),a2.end(),x)));
//     res = min(res,(int)(a3.end()-upper_bound(a3.begin(),a3.end(),x)));
//     res = min(res,(int)(a4.end()-upper_bound(a4.begin(),a4.end(),x)));
//     return 0;
//
//
// }
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
// void anything(){
//
// }


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

// void get_subsets(vector<int> A,int i,vector<int>& sub, vector<vector<int>> & subs, int k){
//     if(sub.size()>=k)subs.push_back(sub);
//     for(int j=i;j<A.size();j++){
//         sub.push_back(A[j]);
//         get_subsets(A,j+1,sub,subs,k);
//     }
//
//     return;
// }

int main()
{
    int n,k;
    cin >> n;
    cin >> k;
    vector<int> A(n,0);
    INV(A,n);
    vector<vector<int>> subs={};
    for (size_t i = 0; i < A.size(); i++)
    {
        for (size_t j = 0; j <= i; j++)
        {
            if(A.size()-i>=k){
                vector<int>  indVect(A.size() -i );
                copy(A.begin() + j , A.end() - i + j , indVect.begin());
                subs.push_back(indVect);
            }
        }
    }


    unordered_map<int,int> mmap={};
    int res=0;
    for(auto v:subs){
        mmap.clear();
        int max_val = 1;
        for(int i=0;i<v.size();i++){
            if(mmap.find(v[i])==mmap.end()) mmap[v[i]]=1;
            else{
                mmap[v[i]]++;
                max_val = max(max_val,mmap[v[i]]);
            }
        }
        if(max_val>=k) res++;
    }
    cout << res << endl;
    return 0;
}





























void anything(){

}
