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
    int N, T, x, y;
    vector < pii > times;
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> x;
            times.push_back({x, 1});
        }
        for(int i = 0; i < N; i++){
            cin >> x;
            times.push_back({x, -1});
        }
        x = y = 0;
        sort(times.begin(), times.end());
        for(int i = 0; i < 2 * N; i++){
            x += times[i].second;
            y = max(y, x);
        }
        cout << y << endl;
        times.clear();
    }
    return 0;
}