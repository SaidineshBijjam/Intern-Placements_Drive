#include <iostream>
#include <vector>

using namespace std;

#define sz(A) (int)A.size()

int main(){
    int N, x, sum, p, q, type;
    cin >> N;

    vector <int> arr, ftree, pref_sum;
    
    sum = 0; 
    arr.push_back(0); 
    pref_sum.push_back(0);
    ftree.push_back(0);
    for(int i = 0; i < N; i++){
        cin >> x; sum += x; 
        arr.push_back(x);
        pref_sum.push_back(sum);
    }

    // Building the tree
    for(int i = 1; i <= N; i++){
        p = -i&i;
        ftree.push_back(pref_sum[i] - pref_sum[i - p]);
        cout << ftree[i] << " ";
    }
    cout << endl;

    // Queries
    cin >> q;
    while(q--){
        cin >> type;
        if(!type) {
            cin >> x >> sum;
            sum -= arr[x];
            for(int i = x; i <= N; i+=(-i&i)) ftree[i] += sum;
            for(int i = 1; i <= N; i++) cout << ftree[i] << " ";
            cout << endl;
        }else {
            cin >> x >> p; sum = 0;
            for(int i = x - 1; i > 0; i-=(-i&i)) sum -= ftree[i];
            for(int i = p; i > 0; i-=(-i&i)) sum += ftree[i];
            cout << sum << endl;
        } 
    }

    return 0;
}