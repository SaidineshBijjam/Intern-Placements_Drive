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
// https://practice.geeksforgeeks.org/problems/equilibrium-point/0

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Main Code Here
    int T, N, x, sum, curr;
    vi input;
    cin >> T;
    while(T--){
        cin >> N;
        sum = 0;
        for(int i = 0; i < N; i++){
            cin >> x; sum += x;
            input.push_back(x);
        }
        curr = 0;
        for(int i = 0; i < N; i++){
            curr += input[i];
            if(curr - input[i] == sum - curr) {
                cout << i + 1 << endl;
                break;
            }
        }
        if(curr == sum && N != 1) cout << -1 << endl;
        input.clear();
    }

    return 0;
}