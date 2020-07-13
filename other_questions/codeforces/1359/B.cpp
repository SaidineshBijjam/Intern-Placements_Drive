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
    int T, n, m, x, y, ans;
    string input;
    cin >> T;
    while(T--){
        cin >> n >> m >> x >> y;
        y = (y < 2 * x)? y: 2*x;
        ans = 0;
        while(n--){
            cin >> input;
            for(int i = 0; i < m; i++){
                if(input[i] == '.'){
                    if(i != m - 1 && input[i+1] == '.'){
                        ans += y; i++;
                    }else ans += x;
                }
            } 
        }
        cout << ans << '\n';
    }
    cout << flush;

    return 0;
}