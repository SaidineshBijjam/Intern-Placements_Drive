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

// https://www.geeksforgeeks.org/minimum-xor-value-pair/
// Run using ( g++ -Wall <filename>.cpp -o <filename>.run ) 
typedef struct node{
    struct node *p[2];
    int count = 0;
}node;

void insert(node *root, int num, int curr){
    if(curr == -1) return;
    int temp = (num & (1 << curr)) >> curr;
    if(root->p[temp] == NULL) {
        node *req = (node *)malloc(sizeof(node));
        req->p[0] = NULL; req->p[1] = NULL; req->count = 0;
        root->p[temp] = req;
    }
    root->p[temp]->count += 1;
    insert(root->p[temp], num, --curr);
    return;
}

int search(node *root, int num, int curr){
    node* req;
    if(curr == -1) return 0;
    int temp = (num & (1 << curr)) >> curr;
    if(root->p[temp] != NULL) { req = root->p[temp]; temp = 0; }
    else { req = root->p[!temp]; temp = 1 << curr; }
    temp |= search(req, num, --curr);
    return temp;
}


int xor_check(vi req){
    node *root = (node *)malloc(sizeof(node));
    root->p[0] = NULL; root->p[1] = NULL; root->count = 0;
    insert(root, req[0], 31);
    int ans = modi;
    for(int i = 1; i < (int)req.size(); i++){
        ans = min(ans, search(root, req[i], 31));
        insert(root, req[i], 31);
    } 
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Main Code Here
    int N, x;
    vi arr;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x;
        arr.push_back(x);
    }
    cout << xor_check(arr) << endl;

    return 0;
}