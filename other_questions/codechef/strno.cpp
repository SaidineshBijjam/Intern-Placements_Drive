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

    lli T, X, K, curr;
    vi primes;
    vi req;
    for(int i = 0; i < (int)1e5; i++) req.push_back(1);
    for(int i = 2; i < 1000; i++){
        if(!req[i]) continue;
        for(int j = 2; j*i < 1e5 + 1;j++) req[i*j] = 0;
    }
    for(int i = 2; i < (int)1e5; i++) if(req[i]) primes.push_back(i);
    
    cin >> T;
    while(T--){
        cin >> X >> K; curr = 0;
        for(int i = 0; i < sz(primes); i++){
            while(X != 1 && X % primes[i] == 0){
                curr++; X /= primes[i];
            }
        }
        if(X != 1) curr++;
        if(curr >= K) cout << 1 << endl;
        else cout << 0 << endl;
    }
 
    return 0;
}