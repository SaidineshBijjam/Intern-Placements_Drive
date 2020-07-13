#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

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

float get_temp(lli m, float a, float b){
    float cups = (float)m;
    return (cups * (a + b) + a) / (2 * cups + 1);
}

lli binary_search(float a, float b, float x){
    lli l = 0, r = 1e18+7;
    lli m = (l + r) / 2;
    while(l < r - 1){
        if(get_temp(m, a, b) > x) l = m;
        else r = m;
        m = (l + r) / 2;
    }
    float temp1 = abs(x - ((a + b) / 2));
    float temp2 = abs(x - get_temp(l, a, b));
    float temp3 = abs(x - get_temp(r, a, b));
    // cout << temp1 << " " << temp2 << " " << temp3 << endl;
    if(temp1 == temp2 && temp2 == temp3) return min(2*l + 1, (lli)2); 
    if(temp1 <= temp2 && temp1 <= temp3) return (lli)2;
    else if(temp2 <= temp3 && temp2 <= temp1) return 2*l + 1;
    else return 2*r + 1;   
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Main Code Here
    float T, h, c, t;
    cin >> T;
    while(T--){
        cin >> h >> c >> t;
        cout << binary_search(h, c, t) << endl;
    }

    return 0;
}