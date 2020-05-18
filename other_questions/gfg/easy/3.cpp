#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

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

// https://practice.geeksforgeeks.org/problems/count-the-triplets/0
// Run using ( g++ -Wall <filename>.cpp -o <filename>.run ) 
int n2logn(vi A){
    int ans = 0, N = sz(A);
    map <int, int> req;
    for(int i = 0; i < N; i++) req[A[i]] = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(req[A[i]- A[j]]) ans++;
        }
    }
    return ans / 2;
}

int n2(vi A){
    int ans = 0, N = sz(A);
    sort(A.begin(), A.end());
    for(int i = N - 1; i > 0; i--){
        int l = 0, r = i - 1;
        while(l < r){
            if(A[l] + A[r] > A[i]) r--;
            else if(A[l] + A[r] < A[i]) l++;
            else { ans++; l++; }
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Main Code Here
    int N, T, x, ans;
    vi A;
    map <int, int> req;
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> x;
            A.push_back(x);
        }
        ans = n2(A);
        if(ans == 0) cout << -1 << endl;
        else cout << ans << endl;
        A.clear();
        req.clear();
    }


    return 0;
}