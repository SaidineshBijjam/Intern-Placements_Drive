#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define sz(A) (int)A.size()

int main(){
    int N, x;
    vector <int> a;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> x; a.push_back(x);
    }

    // Median for c = 1
        sort(a.begin(), a.end());
        cout << "For c = 1: " << a[(N - 1) / 2] << endl;

    // Mean for c = 2
        int sum = 0;
        for(int i = 0; i < N; i++) sum += a[i];
        cout << "For c = 2: " << sum / N << endl;        
    return 0;
}
