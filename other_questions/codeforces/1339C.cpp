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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Main Code Here
    int t, n, x, prev, ans, tps;
    vi req, final;
    cin >> t;
    for(int i = 0; i < 64; i++) final.push_back(0);
    while(t--){
        cin >> n;
        for(int i = 0; i < 64; i++) final[i] = 0;
        prev = MINF;
        for(int i = 0; i < n; i++){
            cin >> x;
            if(prev > x){
                tps = prev - x;
                ans = 0;
                while(tps != 0) {
                    ans++;
                    tps = tps >> 1;
                }
                final[ans] = 1;
                x = prev;
            }
            prev = x;
        }
        for(ans = 64; ans > 0; ans--){
            if(final[ans] == 1) break;
        }
        cout << ans << endl;
    }

    return 0;
}