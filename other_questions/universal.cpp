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
int universal(string A){
    int ans = 0, n = (int)A.size();
    vi req[3];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++) req[j].push_back(0);
    }

    int curr0 = 0, curr1 = 0;
    if(A[0] == '0') {
        req[1][0] = 1;
        curr0 = 1;
    }
    else {
        req[0][0] = 1;
        req[2][0] = 1;
        curr1 = 1;
    }
    for(int i = 1; i < n; i++){
        if(A[i] == '0'){
            curr0++;
            req[0][i] = req[0][i - 1];
            req[1][i] = max(req[0][i] + curr0, req[1][i - 1]);
            req[2][i] = req[2][i - 1];
            curr1 = 0;
        }else {
            curr1++;
            req[0][i] = max(curr1, req[0][i - 1]);
            req[1][i] = req[1][i - 1];
            req[2][i] = max(req[2][i - 1], req[1][i] + curr1); 
            curr0 = 0;
        }
    }
    ans = 0;
    for(int i = 0; i < 3; i++) ans = max(ans, req[i][n- 1]);  
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Main Code Here
    string A;
    cin >> A;
    cout << universal(A) << endl;
    return 0;
}