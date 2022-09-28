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


int main()
{
    int n,x,y;
    cin >> n;
    cin >> x;
    cin >> y;

    vector<int> a(x,0);
    vector<int> b(y,0);

    FOR(i,x){
        cin>>a[i];
    }
    FOR(i,y){
        cin>>b[i];
    }

    int res = 0;
    FOR1(i,n){
        vector<int> tmp;
        int tmp_way = 0;
        int aa,bb;
        for(int j=0;j<a.size();j++){
            if(a[j]==i){
                tmp_way=1;
                aa=j;
            }
        }
        for(int j=0;j<b.size();j++){
            if(b[j]==i){
                tmp_way=2;
                bb=j;
            }
        }

        if(tmp_way==1){
            if(aa!=a.end()-a.begin()-1){
                vector<int> tmp(a.begin()+aa+1,a.end());
                reverse(tmp.begin(),tmp.end());
                
                b.insert(b.end(),tmp.begin(),tmp.end());

                res+=1+tmp.size();
            }else{
                res+=1;
            }
            a.erase(a.begin()+aa);
        }else if(tmp_way==2){
            if(bb!=b.end()-b.begin()-1){
                vector<int> b_tmp(b.begin()+bb+1,b.end());
                reverse(b_tmp.begin(),b_tmp.end());

                a.insert(a.end(),b_tmp.begin(),b_tmp.end());

                res+=1+b_tmp.size();
            }else{
                res+=1;
            }
            b.erase(b.begin()+bb);
        }

    }
    cout <<  res << endl;
    return 0;


}





























void anything(){

}
