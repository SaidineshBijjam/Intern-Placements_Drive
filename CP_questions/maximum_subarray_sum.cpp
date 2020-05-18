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

// Run using ( g++ -Wall maximum_sumarray_sum.cpp -o msm.run ) 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Main Code Here

    int n, x, ans, sum;
    vi req;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        req.push_back(x);
    }

    // O(n3)
    ans = MINF;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int k = i; sum = 0;
            while(k <= j){
                sum += req[k++];
            }
            if(sum > ans) ans = sum;
        }
    }
    cout << ans << endl;

    // o(n2)
    ans = MINF;
    for(int i = 0; i < n; i++){
        sum = 0;
        for(int j = i; j < n; j++){
            sum += req[j];
            if(ans < sum) ans = sum;
        }
    }
    cout << ans << endl;
    
    // o(n) Kadane's algorithm
    ans = MINF, sum = 0;
    for(int i = 0; i < n; i++){
        sum += max(req[i], sum + req[i]); 
        ans = max(ans, sum);
    }
    cout << ans << endl;

    return 0;
}