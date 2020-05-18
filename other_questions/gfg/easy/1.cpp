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

// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0
// Run using ( g++ -Wall <filename>.cpp -o <filename>.run ) 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Main Code Here
    int T, N, x, s;
    vi A;
    cin >> T;
    while(T--){
        cin >> N >> s;
        for(int i = 0; i < N; i++){
            cin >> x;
            A.push_back(x);
        }
        int l = 0, r = 0, sum = 0;
        while(l < N){
            sum += A[r];
            while(sum > s || r == N) sum -= A[l++];
            if(sum < s) r++;
            else break;
        }
        if(sum == s) cout << l+1 << " " << r+1 << endl;
        else cout << -1 << endl;
        // sort(A.begin(), A.end())
        A.clear();
    }
    return 0;
}