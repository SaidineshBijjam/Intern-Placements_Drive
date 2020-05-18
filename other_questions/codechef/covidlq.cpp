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

    int T, N, prev, x;
    bool final;
    cin >> T;
    while(T--){
        final = true; prev = -6;
        cin >> N;
        for(int i = 0; i < N; i++) { 
            cin >> x;
            if(x) {
                final &= (prev <= i - 6);
                prev = i;
            }
        }
        if(final) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}