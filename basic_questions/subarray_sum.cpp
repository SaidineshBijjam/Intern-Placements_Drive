#include <iostream>
#include <vector>

using namespace std;

#define sz(A) (int)A.size()

int main(){
    int N, x, k;
    cin >> N >> k;

    vector <int> arr;
    for(int i = 0; i < N; i++) {
        cin >> x; 
        arr.push_back(x);
    }

    int l, r, sum; sum = l = r = 0;
    while(r < N){
        sum += arr[r++];
        while(sum > k) sum -= arr[l++];
        if(sum == k) cout << l << " " << r << endl;
    }
    return 0;
}