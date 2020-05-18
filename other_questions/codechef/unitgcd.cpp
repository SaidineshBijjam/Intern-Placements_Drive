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
    int T, N;
    cin >> T;
    while(T--){
        cin >> N;
        if(N <= 3){
            cout << 1 << '\n' << N << " ";
            for(int i = 0; i < N; i++) cout << i + 1 << " ";
            cout << '\n';
        }else{
            cout << N/2 << '\n';
            cout << 3 << " ";
            for(int i = 0; i < 3; i++) cout << i + 1 << " "; 
            cout << '\n';
            for(int i = 4; i < N; i+=2){
                cout << 2 << " " << i << " " << i + 1 << '\n';
            } 
            if(N%2 == 0) cout << 1 << " " << N << '\n';
        }
        cout << flush;
    }

    return 0;
}