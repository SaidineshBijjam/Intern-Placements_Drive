#include <bits/stdc++.h>

using namespace std;

#define sz(A) (int)A.size();

void dfs(int curr, vector <long> &ans, vector <int> w){
    int n = sz(w); 
    if(curr >= n/2) return;
    int x1 = 2*curr+1;
    ans[x1] = ans[curr] - 1 - (long)(w[x1] - w[x1 + 1]);
    ans[x1 + 1] = ans[curr] - 1 - (long)(w[x1] - w[x1 + 1]);
    if(x1 < n/2) {
        dfs(x1, ans, w);
        dfs(x1+ 1, ans, w);
    }
    return;
}

vector <long> finallevels(vector <int> wV){
    vector <long> ans;
    int n = sz(wV);
    for(int i = n/2 - 1; i >= 0; i--){
        wV[i] += wV[2*i + 1] + wV[2*i + 2];
    }

    for(int i = 0; i < n; i++) ans.push_back(0);
    dfs(0, ans, wV);
    return ans;
}

int main(){
    int n, x;
    vector <int> w;
    vector <long> ans;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x;
        w.push_back(x);
    }
    ans = finallevels(w);
    for(int i = 0; i < n; i++) cout << ans[i] << endl;
    return 0;
}