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
    int T, N, x, ans;
    vi curr;
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> x; curr.push_back(x);
        }
        sort(curr.begin(), curr.end());
        ans = 0;
        for(int i = 0; i < N; i++){
            if(i + 1 >= curr[i]) ans = i + 1;
        }
        cout << ans + 1 << endl;
        // sort()
        
        curr.clear();
    }
    return 0;
}