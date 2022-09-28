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
    int m;
    cin >> m;
    vector<vector<int>> M(m,vector<int>(m,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin >> M[i][j];
        }
    }

    //左上到右下
    vector<vector<int>> pre_sum(M);
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(i==0&&j==0) continue;
            if(i==0&&j>0){
                pre_sum[i][j]=pre_sum[i][j-1]+pre_sum[i][j];
            }else if(j==0&&i>0){
                pre_sum[i][j]=pre_sum[i-1][j]+pre_sum[i][j];
            }else{
                pre_sum[i][j] = pre_sum[i-1][j]+pre_sum[i][j-1]-pre_sum[i-1][j-1]+pre_sum[i][j];
            }
        }
    }

    //左下到右上
    vector<vector<int>> pre_sum_1(M);
    for(int i=m-1;i>=0;i--){
        for(int j=0;j<m;j++){
            if(i==m-1&&j==0) continue;
            if(i==m-1&&j>0){
                pre_sum_1[i][j]=pre_sum_1[i][j-1]+pre_sum_1[i][j];
            }else if(j==0&&i<m-1){
                pre_sum_1[i][j]=pre_sum_1[i+1][j]+pre_sum_1[i][j];
            }else{
                pre_sum_1[i][j] = pre_sum_1[i+1][j]+pre_sum_1[i][j-1]-pre_sum_1[i+1][j-1]+pre_sum_1[i][j];
            }
        }
    }

    //右下到左上
    vector<vector<int>> pre_sum_2(M);
    for(int i=m-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i==m-1&&j==m-1) continue;
            if(i==m-1&&j<m-1){
                pre_sum_2[i][j]=pre_sum_2[i][j+1]+pre_sum_2[i][j];
            }else if(j==m-1&&i<m-1){
                pre_sum_2[i][j]=pre_sum_2[i+1][j]+pre_sum_2[i][j];
            }else{
                pre_sum_2[i][j] = pre_sum_2[i+1][j]+pre_sum_2[i][j+1]-pre_sum_2[i+1][j+1]+pre_sum_2[i][j];
            }
        }
    }

    //右上到左下
    vector<vector<int>> pre_sum_3(M);
    for(int i=0;i<m;i++){
        for(int j=m-1;j>=0;j--){
            if(i==0&&j==m-1) continue;
            if(i==0&&j<m-1){
                pre_sum_3[i][j]=pre_sum_3[i][j+1]+pre_sum_3[i][j];
            }else if(j==m-1&&i>0){
                pre_sum_3[i][j]=pre_sum_3[i-1][j]+pre_sum_3[i][j];
            }else{
                pre_sum_3[i][j] = pre_sum_3[i-1][j]+pre_sum_3[i][j+1]-pre_sum_3[i-1][j+1]+pre_sum_3[i][j];
            }
        }
    }




    int temp_add=0;
    int left_res = 0;
    for(int i=0;i<m;i++){
        if(pre_sum[i][i]+temp_add!=(i+1)*(i+1)){
            temp_add += (i+1)*(i+1)-pre_sum[i][i];
            pre_sum[i][i] = (i+1)*(i+1);
            left_res++;
        }
    }
    temp_add = 0;
    int left_down_res = 0;
    for(int i=0;i<m;i++){
        if(pre_sum_1[m-1-i][i]+temp_add!=(i+1)*(i+1)){
            temp_add += (i+1)*(i+1)-pre_sum_1[m-1-i][i];
            pre_sum_1[m-1-i][i] = (i+1)*(i+1);
            left_down_res++;
        }
    }
    temp_add = 0;
    int right_down_res = 0;
    for(int i=0;i<m;i++){
        if(pre_sum_2[m-1-i][m-1-i]+temp_add!=(i+1)*(i+1)){
            temp_add += (i+1)*(i+1)-pre_sum_2[m-1-i][m-1-i];
            pre_sum_2[m-1-i][m-1-i] = (i+1)*(i+1);
            right_down_res++;
        }
    }

    temp_add = 0;
    int right_res = 0;
    for(int i=0;i<m;i++){
        if(pre_sum_3[i][m-1-i]+temp_add!=(i+1)*(i+1)){
            temp_add += (i+1)*(i+1)-pre_sum_3[i][m-1-i];
            pre_sum_3[i][m-1-i] = (i+1)*(i+1);
            right_res++;
        }
    }


    int res = INT_MAX;
    res = min(res,left_res);
    res = min(res,left_down_res);
    res = min(res,right_down_res);
    res = min(res,right_res);
    if(res>=2) cout << (res-1)*5 << endl;
    else cout << 0 << endl;




    return 0;
}
