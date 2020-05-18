#include <iostream>
#include <vector>

using namespace std;

#define sz(A) (int)A.size()

int main(){
    vector <pair <int, int> > blocked;
    int N, M, Q, x, y;
    cin >> N >> M >> Q;
    while(Q--){
        cin >> x >> y;
        blocked.push_back({x, y});
    }

    int n = 0, m = 0; 
    long long int ans, mod; mod = 1e9 + 7;
    
    // Finding number of ones
    x = N;
    while(x > 0){
        n += x&1; x = x >> 1;
    }
    x = M;
    while(x > 0){
        m += x&1; x = x >> 1;
    }

    // finding total answer without blocked
    x = n + m; ans = 1;
    while(x > 0){
        ans = (ans * 2) % mod;
        x--;
    }

    cout << ans << endl;
    return 0;
}