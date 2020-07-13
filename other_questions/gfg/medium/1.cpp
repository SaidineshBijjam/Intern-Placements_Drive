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

// https://practice.geeksforgeeks.org/problems/inversion-of-array/0/
// Run using ( g++ -Wall <filename>.cpp -o <filename>.run ) 

lli merge(vector <int> &arr, int l, int r){
    if(l == r) return 0;
    vector <int> temp;
    int i = l, m = (l + r) / 2, j = m + 1; lli k = 0;
    while(i <= m || j <= r){
        if(j > r) temp.push_back(arr[i++]);
        else if(i > m) temp.push_back(arr[j++]);
        else if(arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else {
            temp.push_back(arr[j++]);
            k += (lli)(m - i + 1);

        }
    }
    // for(i = l; i <= r; i++) cout << arr[i] << " "; cout << endl;
    // cout << l << " " << r << " " << k << endl;
    for(i = l; i <= r; i++) arr[i] = temp[i - l];
    return k;
}

long divide(vector <int> &arr, int l, int r){
    if(l == r) return 0;
    int m = (l + r) / 2;
    lli ans = 0;
    ans += divide(arr, l, m);
    ans += divide(arr, m + 1, r);
    ans += merge(arr, l , r);
    return ans;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Main Code Here
    int N, T, x;
    vector <int> input;
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> x;
            input.push_back(x);
        }
        cout << divide(input, 0, N - 1) << endl;
        // for(int i = 0; i < N; i++) cout << input[i] << " ";
        // cout << endl;
        input.clear();
    }

    return 0;
}