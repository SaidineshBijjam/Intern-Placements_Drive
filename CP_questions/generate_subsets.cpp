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

void recursive_generate_subsets(vi &subset, vi data, int idx){
    if(idx == sz(data)){
        for(int i = 0; i < sz(subset); i++) cout << subset[i] << " ";
        cout << endl;
    }else{
        subset.push_back(data[idx]);
        recursive_generate_subsets(subset, data, idx + 1);
        subset.pop_back();
        recursive_generate_subsets(subset, data, idx + 1);
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Main Code Here
    int n, x; vi req, curr;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        req.push_back(x);
    }
    recursive_generate_subsets(curr, req, 0);

    // Normal bitwise method
    for (int b = 0; b < (1<<n); b++) {
        for (int i = 0; i < n; i++) {
            if (b&(1<<i)) curr.push_back(i + 1);
        }
        for(int i = 0; i < sz(curr); i++) cout << curr[i] << " ";
        cout << endl;
        curr.clear();
    }

    return 0;
}