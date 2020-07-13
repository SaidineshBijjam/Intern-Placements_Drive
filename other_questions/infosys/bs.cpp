#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define sz(A) (int)A.size()
#define lli long long int
#define modi (int)1e9+7
#define modl (lli)1e9+7
#define MINF -(int)(1e9+7)


typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef vector<int> vi;
typedef vector<lli> vl; 

// Run using ( g++ -Wall <filename>.cpp -o <filename>.run ) 
int ret_arr(int *curr, int* req, int k, int n, int m){
    int l, r;
    for(int i = 0; i < k; i++) {
        l = max(req[i] - m, 0);
        r = min(req[i] + m, n - 1);
        curr[l] = 1;
        curr[r + 1] = -1;
    }
    int sum = 0;
    for(int i = 0; i < n + 1; i++){
        sum += curr[i];
        curr[i] = sum;
        if(sum == 0) return false;
    }
    return true;
}

void make_zero(int *curr, int n){
    for(int i = 0; i < n; i++) curr[i] = 0;
    return;
}

int bs(int n, int k, int *curr, int *req){
    int l = 0, r = n - 1, m;
    while(l < r){
        m = (l + r) / 2;
        if(ret_arr(curr, req, k, n, m)) r = m;
        else l = r + 1;
        make_zero(curr, n + 1);
    }
    return l;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Main Code Here
    lli T;
    lli N, K;
    while(T--){
        cin >> N >> K;
        int req[K], curr[N + 1];
        make_zero(curr, N + 1);
        for(int i = 0; i < K; i++){
            cin >> req[i];
        }
        cout << bs(N, K, curr, req) << endl;
    }

    return 0;
}