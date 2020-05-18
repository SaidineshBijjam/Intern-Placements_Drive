#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define sz(A) (int)A.size()
#define lli long long int
#define modi (int)1e9+7
#define modl (lli)1e9+7
#define MINF -(lli)(1e18+7)


typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef vector<int> vi;
typedef vector<lli> vl; 

// Run using ( g++ -Wall <filename>.cpp -o <filename>.run ) 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Main Code Here

    lli T, N, x, prev, maxi;
    vl req;
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> x;
            req.push_back(x);
        }
        prev = req[0]; maxi = req[0];
        for(int i = 1; i < N; i++){
            prev = max(req[i], prev + req[i]);
            maxi = max(prev, maxi);
        }
        cout << maxi << endl;
        req.clear();
    }

    return 0;
}