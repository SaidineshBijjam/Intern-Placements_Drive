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

bool comp(pii a, pii b){
    return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Main Code Here
    int N, x, y, k;
    vector < pii > arr;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        arr.push_back({x, y});
    }
    sort(arr.begin(), arr.end(), comp);
    k = 1; x = arr[0].second;
    for(int i = 1; i < N; i++){
        if(arr[i].first > x) {
            k++; x = arr[i].second;
        }
    }
    cout << k << endl;

    return 0;
}