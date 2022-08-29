#include<iostream>
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
//
// //按照string的长度排序
// //map<string,int,cmp>a;
//
// typedef pair<int, int> PAIR;
// bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {
// 	if(lhs.first==rhs.first)
// 		return lhs.second<rhs.second;
// 	else return lhs.first>rhs.first;
// }
//
// struct CmpByValue {
//   bool operator()(const PAIR& lhs, const PAIR& rhs) {
//      if(lhs.first==rhs.first)
// 		return lhs.second<rhs.second;
// 	 else return lhs.first>rhs.first;
//   }
// };
//
// int main()
// {
// 	multimap<int,int>a;
// 	a.insert(make_pair(7,6));
// 	a.insert(make_pair(3,4));
// 	a.insert(make_pair(1,2));
// 	a.insert(make_pair(3,2));
// 	a.insert(make_pair(3,1));
// 	a.insert(make_pair(4,2));
// 	a.insert(make_pair(9,10));
// 	a.insert(make_pair(11,2));
// 	a.insert(make_pair(14,6));
// 	a.insert(make_pair(4,2));
// 	vector<PAIR> name_score_vec(a.begin(), a.end());
//     //sort(name_score_vec.begin(), name_score_vec.end(), CmpByValue());
//     sort(name_score_vec.begin(), name_score_vec.end(), cmp_by_value);
//      for (int i = 0; i != name_score_vec.size(); ++i) {
// 		 cout << name_score_vec[i].first<<name_score_vec[i].second<< endl;
//       }
// 	return 0;
// }

void helper(vector<int>& cookies, int idx, vector<vector<int>> ith_cookies, int k,unordered_map<int,int>& mymap){
    vector<vector<int>> new_ith_cookies(ith_cookies);
    // for(auto i_c:ith_cookies){
    //     for(auto v:i_c){
    //         cout << v << " ";
    //     }
    //     cout << "|| ";
    // }
    // cout<<endl;
    bool add_pair = false;
    if(idx==cookies.size()){
        int sum=0;
        vector<int> val_sum;
        for(auto i_c:ith_cookies){
            if(i_c.size()==0||i_c.size()>cookies.size()-k+1) return;

            for(auto v:i_c){
                sum+=v;
            }
            val_sum.push_back(sum);
            sum = 0;
        }
        int max_val=INT_MIN;
        int min_val=INT_MAX;
        for(auto va:val_sum){
            max_val = max(max_val,va);
            min_val = min(min_val,va);
        }
        mymap[max_val-min_val]=max_val;
        return;
    }else{
        for(int i=0;i<k;i++){
            new_ith_cookies[i].push_back(cookies[idx]);
            helper(cookies,idx+1,new_ith_cookies,k,mymap);
            new_ith_cookies[i].pop_back();
        }
    }
    return ;
}

int my_distributeCookies(vector<int>& cookies, int k,unordered_map<int,int>& mymap) {
    sort(cookies.begin(),cookies.end());
    vector<vector<int>> ith_cookies(k);
    helper(cookies,0,ith_cookies,k,mymap);

    int min_key = INT_MAX;
    for(auto it=mymap.cbegin();it!=mymap.cend();it++){
        min_key = min(min_key,(*it).first);
    }
    return mymap[min_key];

}

int longestSubsequence(string s, int k) {

    int tmp = stoi(s, nullptr, 2);
    if(tmp <= k) return s.size();

    map<int,int,std::greater<int>> mymap;
    int cnt_0=0;
    int res = INT_MIN;
    int start = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            mymap[i]=cnt_0;
            res=max(res,cnt_0);
            start = i;
        }
        else{
            cnt_0++;
        }
    }
    string res_s(res,'0');
    cout << res << endl;
    cout << res_s<<endl;
    cout << start << endl;
    while(start<s.size()){
        res_s.push_back(s[start]);
        mymap.erase(start);
        tmp=stoi(res_s, nullptr, 2);
        if(tmp>k) return res_s.size()-1;
        start++;
        cout << res_s<<endl;
    }
    for(auto it=mymap.cbegin();it!=mymap.cend ();it++){
        res_s.insert((*it).second,1,'1');
        tmp = stoi(res_s, nullptr, 2);
        if(tmp>k) return res_s.size()-1;
    }
    return res_s.size();
}


int main(){
    longestSubsequence("001010101011010100010101101010010",93951055);
    return 0;
}
