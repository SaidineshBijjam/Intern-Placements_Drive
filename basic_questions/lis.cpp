#include <iostream>
#include <vector>

using namespace std;

#define sz(A) (int)A.size()

int lis_n2(vector <int> seq, vector <int> len){
    int ans = 0;
    for(int i = 1; i < sz(seq); i++){
        for(int j = 0; j < i; j++){
            if(seq[i] > seq[j]){
                len[i] = max(len[i], len[j] + 1);
            }
        }
        ans = max(len[i], ans);
    }

    return ans;
}

int lis_nlogn(vector <int> seq){
    int m, l, r;
    vector <int> req; req.push_back(seq[0]);
    for(int i = 1; i < sz(seq); i++){
        if(seq[i] > req[sz(req) - 1]) req.push_back(seq[i]);
        else{
            m = (l + r) / 2; l = 0; r = sz(req) - 1;
            while(l < r){
                if(seq[i] < req[m]) r = m;
                else if(seq[i] > req[m]) l = m + 1;
                m = (l + r) / 2;
            }
            req[r] = seq[i]; 
        }
    }

    // for(int i = 0; i < sz(req); i++) cout << req[i] << " "; cout << endl;
    return sz(req);
}


int main(){
    int N, input;
    cin >> N;
    vector <int> seq, len;
    for(int i = 0; i < N; i++){
        cin >> input; seq.push_back(input);
        len.push_back(1); 
    }

    // cout << lis_n2(seq, len) << endl;
    cout << lis_nlogn(seq) << endl;
    return 0;
}