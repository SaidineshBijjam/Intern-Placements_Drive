#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define sz(A) (int)A.size()
#define lli long long int
#define modi (int)1e9+7
#define modl (lli)1e9+7

typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef vector<int> vi;
typedef vector<lli> vl; 

// Run using ( g++ -Wall <filename>.cpp -o <filename> ) 
struct compare { 
    bool operator()(const pair<int, int>& value, const int& key) { 
        return (value.first < key); 
    } 
    bool operator()(const int& key,  const pair<int, int>& value) { 
        return (key < value.first); 
    } 
}; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Main Code Here
    int n, x, sum, rems, l, r;
    vector < pii > a;
    cin >> n;
    sum = rems = 0;
    for(int i = 0; i < n; i++){
        cin >> x; sum += x;
        a.push_back(x);
        csum.push_back({sum, i});
    }
    
    sort(csum.begin(), csum.end());
    x = 0;
    for(int i = 0; i < N - 1; i++){
        if(binary_search(csum.begin(), csum.end(), -x, compare())){
            l = lower_bound(csum.begin(), csum.end(), -x, compare());
            r = upper_bound(csum.begin(), csum.end(), -x, compare());
            
        }
        x += a[i]
    }


    return 0;
}