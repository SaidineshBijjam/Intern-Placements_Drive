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
struct P {
    int x, y;
    bool operator<(const P &p) {
        if (x != p.x) return x < p.x;
        else return y < p.y;
    } //comparison operator
};

bool comp(string a, string b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}   //comparison function to pass as argument into a sort function

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

// Bubble Sort
void bubble_sort(vi &arr, int N){
    for(int i = 0; i < N; i++){
        for(int j = 1; j < N - i; j++){
            if(arr[j - 1] > arr[j]) swap(&arr[j - 1], &arr[j]);
        }
    }
    return;
}

void merge(vi &arr, int l, int r){
    int m = (l + r) / 2;
    vector <int> req;
    int i = l, j = m + 1;
    while(i <= m || j <= r){
        if(i > m) req.push_back(arr[j++]);
        else if(j > r) req.push_back(arr[i++]);
        else if(arr[i] > arr[j]) req.push_back(arr[j++]);
        else req.push_back(arr[i++]);
    }
    for(int i = 0; i < sz(req); i++) arr[l + i] = req[i];
    return;
}

void mergesort(vi &arr, int l, int r){
    if(l == r) return;
    int m = (l + r) / 2;
    mergesort(arr, l, m);
    mergesort(arr, m + 1, r);
    merge(arr, l, r);
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Main Code Here

    int N, x; vi arr;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x; arr.push_back(x);
    }

    mergesort(arr, 0, N - 1);
    sort(arr.begin(), arr.end()); //increasing order
    sort(arr.rbegin(), arr.rend()); //decreasing order

    for(int i = 0; i < N; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}