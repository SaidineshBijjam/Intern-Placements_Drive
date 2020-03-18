#include <iostream>
#include <vector>

using namespace std;

#define sz(A) (int)A.size()

void update(vector <int> &req, int idx, int val){
    idx += sz(req) / 2; req[idx] = val; idx /= 2;
    while(idx >= 1){
        req[idx] = req[idx * 2] + req[ 2 * idx + 1];
        idx /= 2;
    } 
    return;
}

int sum(vector <int> req, int l, int r){
    int ans =  0;
    l += sz(req) / 2; r += sz(req) / 2;
    while(l <= r){
        if(l%2) ans += req[l++];
        if(!(r%2)) ans += req[r--];
        l /= 2; r /= 2;
    }
    return ans;
}

int main(){

    int N, Q, x, pN, idx, val, type;
    cin >> N >> Q;
    pN = 1;
    while(pN < N) pN *= 2;

    vector <int> req;

    for(int i = 0; i < 2 * pN; i++) req.push_back(0);

    for(int i = 0; i < N; i++) {
        cin >> x;
        req[i + pN] = x;
    }

    for(int i = pN - 1; i > 0; i--){
        req[i] = req[2*i] + req[2*i + 1];
    }

    while(Q--){
        cin >> type;
        cin >> idx >> val;
        if(type) update(req, idx, val); 
        else cout << "Sum: " << sum(req, idx, val) << endl;
    }

    for(int i = 0; i < 2*pN; i++) cout << req[i] << " ";
    cout << endl;

    return 0;
}