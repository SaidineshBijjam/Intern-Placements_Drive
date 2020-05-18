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
    int N, x, ans, temp;
    vi coins;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> x;
        coins.push_back(x);
    }
    cin >> x; ans = 0;

    sort(coins.begin(), coins.end());

    // greedy solution (works only in special cases)
    int curr = sz(coins) - 1;
    while(x > 0 && curr >= 0){
        if(coins[curr] < x){
            temp = x / coins[curr];
            ans += temp;
            x -= coins[curr] * temp;
        }
        curr--;
    }
    cout << ans << endl;

    // DP solution (always works)

    return 0;
}