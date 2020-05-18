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

// Run using ( g++ -Wall <filename>.cpp -o <filename> ) 

int main(){
    ios::sync_with_stdio(false); // This removes the sync between c++, c i/o (not both streams have different buffers)
    cin.tie(NULL); /* This unties cin, cout. 
    This means that we need to flush everytime before we take an input if we want an output. 
    Normally c++ automatically does this for us*/
    
    // Main Code Here

    // Check the output of this small snippet of code and reason it
    cout << "Hello ";
    printf("World");
    cout << "!!!" << endl; 


    // use '\n' when flushing is not required instead of endl
    // Because flushing everytime takes more time 
    string s;
    getline(cin, s); //This gets the wholeline including spaces (new line not included at the last)
    cout << s << endl;

    int x; //when we dont know how input is to be taken
    while(cin >> x){ 
        // Break condition at the end
    }

    // To read or write into files using cin, cout
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    return 0;
}