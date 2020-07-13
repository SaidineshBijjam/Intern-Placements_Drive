#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>


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

int bfs(queue < pii > req, int b){
    pii curr = req.front();
    while(curr.first != b){
        req.push({curr.first * 2 , curr.second + 1});
        if(curr.first % 2) req.push({curr.first - 1, curr.second + 1});
        else {
            req.push({curr.first + 1, curr.second + 1});
            req.push({curr.first / 2 , curr.second + 1});
        }
        req.pop();
        curr = req.front();
    }
    return req.front().second;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Main Code Here
    lli T;
    lli a, b;
    queue < pii > req;
    cin >> T;
    while(T--){
        cin >> a >> b;
        req.push({a, 0});
        cout << bfs(req, b) << endl;
    }

    return 0;
}