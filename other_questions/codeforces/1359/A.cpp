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
    int T, n, m, k, eP;
    cin >> T;
    while(T--){
        cin >> n >> m >> k;
        eP = n / k;
        if((eP == 1 && m != 1) || (n == m)) cout << 0 << endl;
        else if(m <= eP) cout << m << endl;
        else cout << eP - ((m - eP) / (k - 1) + (((m- eP) % (k - 1) == 0)? 0 : 1)) << endl;
    }

    return 0;
}