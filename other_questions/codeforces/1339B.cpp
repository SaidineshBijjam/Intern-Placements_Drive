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
    int t, n, x, l, r;
    vi req, final;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> x;
            req.push_back(x);
        }
        sort(req.begin(), req.end());
        if(n % 2){
            final.push_back(n/2);
            final.push_back(n/2 + 1);
            final.push_back(n/2 - 1);
            l = -1; r = 1;
            for(int i = 0; i < n - 3; i++){
                if(final[i + 2] > n/2) final.push_back(n/2 + (--l));
                else final.push_back(n/2 + (++r));
            }
        }else{
            final.push_back(n/2);
            final.push_back(n/2 - 1);
            l = -1; r = 0;
            for(int i = 0; i < n - 2; i++){
                if(final[i + 1] < n/2) final.push_back(n/2 + (++r));
                else final.push_back(n/2 + (--l));
            }
        }
        for(int i = 0; i < n; i++) cout << req[final[i]] << " ";
        cout << endl;
        req.clear();
        final.clear();
    }

    return 0;
}