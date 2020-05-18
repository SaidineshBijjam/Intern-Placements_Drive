#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> //For abs to work with floating points

using namespace std;

#define sz(A) (int)A.size()
typedef long long int lli;

#define modi (int)1e9+7
#define modl (lli)1e9+7

// Run using ( g++ -Wall <filename>.cpp -o <filename> ) 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Main Code Here
    
    int x;
    // Remainder of negitive number is negitive in c++
    x = x % modi;
    if(x < 0) x += modi;

    float a, b;
    // Do not compare floats using (a == b).
    // This is because floats have rounding errors. So use the below method
    if(abs(a - b) < 1e-9){

    }

    return 0;
}