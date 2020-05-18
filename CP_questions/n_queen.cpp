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
void search(vi &pos,vi &col, vi &d1, vi &d2){
    int n = sz(col);
    if(sz(pos) == n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j == pos[i]) cout << "x";
                else cout << "o";
            }
            cout << endl;
        }
        cout << endl;
    }else{
        int r = sz(pos); 
        for(int c = 0; c < n; c++){
            if(col[c] || d1[r+c] || d2[r-c+n-1]) continue;
            col[c] = d1[r+c] = d2[r-c+n-1] = 1;
            pos.push_back(c);
            search(pos, col, d1, d2);
            col[c] = d1[r+c] = d2[r-c+n-1] = 0;
            pos.pop_back();
        }
    }
    return;

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Main Code Here
    int n;
    cin >> n;

    vi col, diag1, diag2, pos;
    for(int i = 0; i < n; i++) col.push_back(0);
    for(int i = 0; i < 2*n-1; i++) {
        diag1.push_back(0);
        diag2.push_back(0);
    }
    search(pos, col, diag1, diag2);

    return 0;
}