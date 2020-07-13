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
    int T, n, m, temp;
    cin >> T;
    while(T--){
        cin >> n >> m;
        temp = min(n, m);
        n = max(n, m); m = temp;
        cout << m * (n / 2) + (n % 2) * ((m + 1) / 2) << '\n';
    }

    return 0;
}