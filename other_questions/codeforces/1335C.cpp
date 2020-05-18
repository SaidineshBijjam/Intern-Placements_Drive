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
    int t, n, x, dist, same;
    vi arr;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> x;
            arr.push_back(x);
        }
        sort(arr.begin(), arr.end());
        same = 0; dist = 0;
        for(int i = 0; i < n;){
            x = i;
            while(x < n && arr[i] == arr[x]) x++;
            same = max(same, x - i);
            i = x;
            dist++;
        }
        // cout << dist << " " << same << endl;
        arr.clear();
        if(dist - 1 >= same) cout << same << endl;
        else if(same - 1 >= dist) cout << dist << endl;
        else cout << same - 1 << endl;
    }

    return 0;
}