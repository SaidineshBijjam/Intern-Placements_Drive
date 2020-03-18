#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define sz(A) (int)A.size()

int main(){
    int N, sum, x;
    cin >> N >> sum;

    vector <int> arr;
    for(int i = 0; i < N; i++){
        cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());

    int l, r;
    for(int i = 0; i < N; i++){
        l = i + 1; r = N - 1;
        while(l < r){
            if(arr[l] + arr[r] + arr[i] == sum) break;
            else if(arr[l] + arr[r] + arr[i] < sum) l++;
            else if(arr[l] + arr[r] + arr[i] > sum) r--;
        }
        if(l < r && arr[l] + arr[r] + arr[i] == sum) cout << l << " " << r << " " << i << endl;
    }

    return 0;
}