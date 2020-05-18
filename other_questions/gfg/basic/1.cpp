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

// https://practice.geeksforgeeks.org/problems/missing-number-in-array/0
// Run using ( g++ -Wall <filename>.cpp -o <filename>.run ) 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Main Code Here
    int T, N, x, final;
    cin >> T;
    while(T--){
        cin >> N;
        final = 0;
        for(int i = 1; i < N; i++){
            cin >> x;
            final ^= (x ^ i);
        }
        cout << (final ^ N) << endl;
    }

    return 0;
}