#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define sz(A) (int)A.size()
#define lli long long int
#define modi ((int)1e9+7)
#define modl ((lli)1e9+7)
#define MINF (-(int)(1e9+7))


typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef vector<int> vi;
typedef vector<lli> vl; 

// Run using ( g++ -Wall <filename>.cpp -o <filename>.run ) 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Main Code Here
    lli T, N, x; lli ans;
    vl input;
    cin >> T;
    while(T--){
        cin >> N;
        for(lli i = 0; i < N; i++){
            cin >> x;
            input.push_back(x);
        }
        sort(input.begin(), input.end());
        x = 0; ans = 0;
        while(--N > -1){
            if(input[N] + x <= 0) break; 
            ans = (ans + (input[N] + x)) % modl;
            x--;
        }
        cout << ans << endl;
        input.clear();
    }

    return 0;
}