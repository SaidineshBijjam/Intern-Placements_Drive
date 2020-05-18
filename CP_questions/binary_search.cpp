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

int lbinary_search(vi arr, int x){
    int l = 0, r = sz(arr) - 1, idx;
    idx = (l + r) / 2;
    while(l < r){
        if(arr[idx] < x) l = idx + 1;
        else if(arr[idx] > x) r = idx - 1;
        else r = idx;
        idx = (l + r) / 2;
    }
    if(arr[idx] == x) return idx;
    else return -1;
}

int rbinary_search(vi arr, int x){
    int l = 0, r = sz(arr) - 1, idx;
    idx = (l + r + 1) / 2;
    while(l < r){
        if(arr[idx] < x) l = idx + 1;
        else if(arr[idx] > x) r = idx - 1;
        else l = idx;
        idx = (l + r + 1) / 2;
    }
    if(arr[idx] == x) return idx;
    else return -1;
}

// General Binary Search problem: Minimum Possible solution
bool ok(int k){
    // Dummy function
    return true;
}

int binary_search(vi arr){
    int l = 0, r = modi, idx;
    idx = (l + r) / 2;
    while(l < r){
        if(ok(idx)) r = idx;
        else l = idx + 1;
        idx = (l + r) / 2;
    }
    return idx;
}

// Can be used find the maximum value of a function

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Main Code Here

    int N, x;
    vi req;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x;
        req.push_back(x);
    }
    sort(req.begin(), req.end());

    cin >> x;
    cout << lbinary_search(req, x) << " " << rbinary_search(req, x) << endl;

    return 0;
}