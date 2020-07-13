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

// https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0
// Run using ( g++ -Wall <filename>.cpp -o <filename>.run ) 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Main Code Here
    int T, N, x, curr_max;
    vi input, ans;
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> x;
            input.push_back(x);
        }
        curr_max = -1;
        for(int i = N - 1; i >= 0; i--){
            curr_max = max(curr_max, input[i]);
            if(curr_max == input[i]) ans.push_back(input[i]);
        }
        reverse(ans.begin(), ans.end());
        for(int i = 0; i < (int)ans.size(); i++) cout << ans[i] << " ";
        cout << endl;
        ans.clear();
        input.clear();
    }
    return 0;
}