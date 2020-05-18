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
void search(vi &data, vi &permutation, vi &chosen){
    if(sz(permutation) == sz(data)){
        for(int i = 0; i < sz(permutation); i++) cout << permutation[i] << " ";
        cout << endl;
    }else{
        for(int i = 0; i < sz(data); i++){
            if(chosen[i]) continue;
            chosen[i] = 1; permutation.push_back(data[i]);
            search(data, permutation, chosen);
            chosen[i] = 0; permutation.pop_back();
        }
    }
    return;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Main Code Here
    int n, x; vi req, chosen, curr;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        req.push_back(x);
        chosen.push_back(0);
    }


    search(req, curr, chosen);


    return 0;
}