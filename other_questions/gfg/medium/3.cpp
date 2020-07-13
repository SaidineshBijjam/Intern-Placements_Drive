#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

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

// https://practice.geeksforgeeks.org/problems/trapping-rain-water/0
// Run using ( g++ -Wall <filename>.cpp -o <filename>.run ) 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Main Code Here
    vi A;
    int T, N, x, l, r, ans, lm, rm;
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> x; A.push_back(x);
        }
        l = 0; r = N - 1;
        lm = rm = ans = 0;
        while(l <= r){
            if(lm < rm){
                if(A[l] > lm) lm = A[l];
                ans += (lm - A[l++]);
            }else{
                if(A[r] > rm) rm = A[r];
                ans += (rm - A[r--]);
            }
        }
        cout << ans << endl;
        A.clear();

    }

    return 0;
}