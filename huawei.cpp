#include<bits/stdc++.h>
using namespace std;
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


int main()
{
    int n,r;
    cin >> n >> r;
    vector<int> num(n,0);
    INV(num,n);
    vector<vector<int>> all_req(r,vector<int>(2,0));
    
    FOR(i,r){
        FOR(j,2){
            cin>> all_req[i][j];
        }
    }



    vector<vector<int>> G(n);
    vector<int> res={};
    vector<int> depth(n,0);

    for(auto req:all_req){
        depth[req[1]]++;
        G[req[0]].push_back(req[1]);
    }

    FOR(i,n){
        cout << i << " : ";
        for(auto g:G[i]){
            cout << g << " ";
        }
        cout << endl;
    }

    function<void(int)> dfs=[&](int m){
        res.push_back(m);
        for(auto r: res){
            cout << r << " ";
        }
        cout << endl;
        depth[m]--;
        for(auto relation:G[m]){
            //if(--depth[relation]==0){
            //    dfs(relation);
            //}
            depth[relation]-=1;
        }
    };

    for(int i=0;i<n;){
        if(depth[i]==0){
            dfs(i);
            i=0;
            continue;
        }
        i++;
    }

    if(res.size()==n){
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout << res[i] << " ";
            }else{
                cout << res[i];
            }
        }
        return 0;
    }
    cout << "-1" << endl;
    return 0;


}
