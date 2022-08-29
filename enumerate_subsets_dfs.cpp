#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>& res, vector<int>& nums,  int sum, int pos) {

    for (int i = pos; i < nums.size(); ++i) {
        res.push_back(sum + nums[i]);
        dfs(res, nums,  sum + nums[i], i + 1); // i + 1 instead of pos + 1
    }
    return;
}

void dfs1(vector<vector<int>>& res, vector<int>& nums,  vector<int>& sum, int pos) {

    for (int i = pos; i < nums.size(); ++i) {
        sum.push_back(nums[i]);
        res.push_back(sum);
        dfs1(res, nums,  sum, i + 1); // i + 1 instead of pos + 1
    }
    return;
}

int main() {
    vector<int> test = {1, 2, 3};
    vector<vector<int>> res;
    vector<int> sum;
    dfs1(res,test,sum, 0);
    cout << res.size() << endl;
    copy(res.begin(), res.end(), ostream_iterator<int>(cout , " "));
    cout <<endl;
    return 0;
}
