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

int fantastic(vector <int> req){
    int count[4];
    for(int i = 0; i < 4; i++) count[i] = 0;
    for(int i = 0; i < (int)req.size(); i++) count[req[i] % 4]++;
    int ans = 0, temp;
    temp = min(count[1], count[3]);
    ans += temp; count[1] -= temp; count[3] -= 3;
    temp = count[2] / 2;
    ans += temp; count[2] -= temp * 2;
    if(count[2] == 1){
        if(count[1] > 2){
            count[1] -= 2;
            count[2] -= 1;
            ans += 2;
        }else if(count[3] > 2){
            count[3] -= 2;
            count[2] -= 1;
            ans += 2;
        }
    }
    if(count[1] > 4){
        
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Main Code Here
    int N, x;
    cin >> N;
    vi req;

    for(int i = 0; i < N; i++){
        cin >> x;
        req.push_back(x);
    }

    cout << fantastic(req) << endl;


    return 0;
}