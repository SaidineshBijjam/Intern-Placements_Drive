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
    lli T, N, x, f, t;
    vl req, l;
    cin >> T;
    for(int i = 0; i < (int)1e5 + 1; i++){
        req.push_back(0);
        l.push_back(0);
    }
    while(T--){
        cin >> N;
        t = -1;
        for(lli i = 0; i < N; i++){
            cin >> x; f = 0;
            while(x%2 == 0 && f <= 1) {
                f++; x /= 2;
            }
            l[i] = t; req[i] = f;
            if(f != 0) t = i; 
        }
        t = N; f = 0;
        for(lli i = N - 1; i >= 0; i--){
            if(req[i] == 1) f += ((i - l[i]) * (t - i));
            if(req[i] != 0) t = i;
        }
        f = ((N * (N + 1))/2) - f;
        cout << f << '\n';
    }
    cout << flush;
    return 0;
}