#include<bits/stdc++.h>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

#pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define F first
#define S second
#define vec vector
#define pb push_back
#define pll pair<ll, ll>
#define pdd pair<ld, ld>
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, int>
#define pnn pair<Node*, Node*>
#define all(m) m.begin(), m.end()
#define uid uniform_int_distribution
#define uniq(m) sort(all(m)); m.erase(unique(all(m)), m.end());
#define fast cin.tie(0); cout.tie(0); cin.sync_with_stdio(0); cout.sync_with_stdio(0);
using namespace std;
using str = string;
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;

template<typename T> bool chmin(T& a, const T& b) {return b < a ? a = b, 1 : 0;}
template<typename T> bool chmax(T& a, const T& b) {return b > a ? a = b, 1 : 0;}
inline uint leq_pow2(uint x) {return 1u << __lg(x);}
inline ull leq_pow2ll(ull x) {return 1ull << __lg(x);}
inline uint geq_pow2(uint x) {return x & (x - 1) ? 2u << __lg(x) : x;}
inline ull geq_pow2ll(ull x) {return x & (x - 1) ? 2ull << __lg(x) : x;}
inline ll sqd(ll x1, ll y1, ll x2, ll y2) {return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);}
inline ll sqd(pll p1, pll p2) {return (p1.F - p2.F) * (p1.F - p2.F) + (p1.S - p2.S) * (p1.S - p2.S);}


// struct cmp  //自定义比较规则
// {
//   bool operator() (const string& str1, const string& str2)
//   {
//     return str1.length() < str2.length();
//   }
// };
// greater<>()

void helper(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<long long> v_vec(s.size(),0);
    long long sum=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='L'){
            v_vec[i]=(long long)i-0;
        }else{
            v_vec[i]=(long long)s.size()-1-i;
        }
        sum+=v_vec[i];
    }

    vector<long long> f_res(s.size(),0);
    vector<int> new_vec={};
    int s_n = s.size();
    for(int i=0;i<s_n;i++){
        if((s.size()-1-i>i-0&&s[i]=='L')||(s.size()-1-i<i-0&&s[i]=='R')){
            new_vec.push_back(abs(s_n-1-i-i));
        }
    }
    sort(new_vec.begin(),new_vec.end(),greater<>());
    for(int i=0;i<s_n;i++){
        if(i<new_vec.size()) sum+=(long long)new_vec[i];
        f_res[i]=sum;
    }

    for(auto f:f_res){
        cout << f << " ";
    }
    cout << endl;

    return;
}


int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        helper();
    }
    return 0;
}
