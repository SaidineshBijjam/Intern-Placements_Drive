#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define sz(A) (int)A.size()

int main(){
    int N, x, sum;
    cin >> N >> sum;

    vector <int> arr;

    for(int i = 0; i < N; i++){
        cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());
    int l, r;
    l = 0; r = N - 1;
    while(l < r){
        if(arr[l] + arr[r] == sum) break;
        else if(arr[l] + arr[r] < sum) l++;
        else r--; 
    }

    if(l != r && sum == arr[l] + arr[r]) cout << l << " " << r;
    else cout << "No";
    cout << endl;

    return 0;
}