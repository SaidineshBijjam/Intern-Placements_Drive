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
int search(int count, int n, int x, int y, vector < vector <int> > &req){
    int ans = 0;
    if(x == n - 1 && y == n - 1){
       if(count == n*n - 1) return ++ans;
       else return ans;
    } 
    
    int l, r, d, u; l = r = d = u = 0;
    if(x > 0 && !req[x - 1][y]) l = 1;
    if(x < n - 1 && !req[x + 1][y]) r = 1;
    if(y > 0 && !req[x][y - 1]) u = 1;
    if(y < n - 1 && !req[x][y + 1]) d = 1;

    if((l&r) && !(u|d)) return ans;
    if((u&d) && !(l|r)) return ans;

    count++;
    req[x][y] = 1;
    if(l) ans += search(count, n, x - 1, y, req);
    if(r) ans += search(count, n, x + 1, y, req);
    if(u) ans += search(count, n, x, y - 1, req);
    if(d) ans += search(count, n, x, y + 1, req);
    req[x][y] = 0;
    count--;
    return ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Main Code Here
    int n;
    cin >> n;
    vector < vector <int> > req;
    for(int i = 0; i < n; i++){
        vector <int> temp;
        for(int j = 0; j < n; j++) temp.push_back(0);
        req.push_back(temp);
    }
    cout << search(0, n, 0, 0, req) << endl;

    return 0;
}