#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <bitset>
#include <deque>
#include <stack>
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Main Code Here

    // dynamic arrays: push_back, pop_back, clear, size
    vi req = {1, 3, 2, 5, 4};
    vi req1(10, 5); 
    for(auto x: req){
        cout << x << endl;
    }
    string a = "hatti";

    // Sets: insert, removal, search, count, erase
    set <int> req2 = {2, 5, 6, 7}; //balanced binary tree
    unordered_set <int> req3; //hashing
    multiset <int> req4; //count returns how many are present 
    for(auto x: req2){
        cout << x << '\n';
    }
    req4.erase(req4.find(5)); //erases one instance of 5 from multiset
    req4.erase(5); //erases all instances of 5 from multiset

    // Maps: count
    map <int, int> req5;
    if(req5.count(4)){
        //checks if key 4 is present
    }
    for (auto x : req5) {
        cout << x.first << " " << x.second << "\n";
    }

    // Iterator begin, end
    auto it = req.begin(); it++; it--;

    // BitSet: Efficient bitwise operations
    bitset<10> req6(string("0010011010")); // from right to left
    cout << req6[4] << "\n"; // 1
    cout << req6[5] << "\n"; // 0

    // Deque: implementation which helps us to access both front and back of the array efficiently
    // pop_front, pop_back, push_back, push_front, front, back
    deque <int> req7; 

    // Stack: implementation which helps us to access both front of the array efficiently
    // push, pop, top
    stack <int> req8;

    // PriorityQueue: push, pop, top, Default: MaxHeap
    priority_queue< int, vector<int>, greater<int> > q; //MinHeap
 
    // Policy Based Data Structures: indexed_set --> can find the index of a certain element when sorted

    // Comparing sorting, set, unordered_set for a problem


    return 0;

}