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
// https://practice.geeksforgeeks.org/problems/reverse-array-in-groups/0

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Main Code Here
    int N, T, x, k;
    vi req;
    cin >> T;
    while(T--){
        cin >> N >> k;
        for(int i = 0; i < N; i++){
            cin >> x; req.push_back(x);
        }
        for(int i = 0; i < N / k; i++){
            reverse(req.begin() + (i * k), req.begin() + k + (i * k));
        }
        reverse(req.begin() + (N - (N % k)), req.end());
        for(int i = 0; i < N; i++) cout << req[i] << " ";
        cout << endl;
        req.clear();
    }

    return 0;
}