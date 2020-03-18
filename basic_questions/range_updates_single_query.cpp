#include <iostream>
#include <vector>

using namespace std;

#define sz(A) (int)A.size()


void update(vector <int> &ftree, int val, int l, int r){
    int N = sz(ftree);
    for(int i = l; i < N; i += i&-i){
        ftree[i] += val;
    }

    for(int i = r; i < N; i += i&-i){
        ftree[i] -= val;
    }

    return;
}

int pos_val(vector <int> ftree, int idx){
    int sum = 0;
    for(int i = idx; i >= 1; i -= i&-i){
        sum += ftree[i];
    }
    return sum;
}

int main(){
    int N, x, sum, idx1, idx2, Q;
    cin >> N;

    // taking input
    vector <int> req, ftree; req.push_back(0);
    ftree.push_back(0);
    for(int i = 0; i < N; i++){
        cin >> x;
        req.push_back(x);
        ftree.push_back(0);
    }
    req.push_back(0); ftree.push_back(0);

    // difference array
    for(int i = 1; i <= N + 1; i++) ftree[i] = req[i] - req[i - 1];
    for(int i = 1; i <= N + 1; i++) cout << ftree[i] << " "; cout << endl;
    cout << "Difference Array Done" << endl;

    //Prefix sum array 
    sum = 0;
    for(int i = 1; i <= N + 1; i++) {
        sum += ftree[i];
        req[i] = sum;
    }
    for(int i = 1; i <= N + 1; i++) cout << req[i] << " "; cout << endl;
    cout << "Prefix Array Done" << endl;

    // Initializing Fenwick Tree
    for(int i = 1; i <= N + 1; i++){
        sum = i&-i;
        ftree[i] = req[i] - req[i - sum]; 
    }
    for(int i = 1; i <= N + 1; i++) cout << ftree[i] << " "; cout << endl;
    cout << "F Tree Done" << endl;
    
    // Queries
    cin >> Q;
    while(Q--){
        cin >> x;
        if(x) {
            cin >> sum >> idx1 >> idx2;
            update(ftree, sum, idx1, idx2 + 1);
        }else{
            cin >> idx1;
            cout << pos_val(ftree, idx1) << endl;
        }
    }
    return 0;
}