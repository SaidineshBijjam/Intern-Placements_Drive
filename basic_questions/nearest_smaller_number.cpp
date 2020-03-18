#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define sz(A) (int)A.size()

int main(){
    int N, x;
    cin >> N;

    vector <int> arr;
    stack <int> req;
    for(int i = 0; i < N; i++){
        cin >> x;
        arr.push_back(x);
    }

    for(int i = 0; i < N; i++){
        while(!req.empty() && req.top() >= arr[i]) req.pop();
        if(!req.empty()) cout << req.top() << endl;
        else cout << "NO" << endl;
        req.push(arr[i]);
    }

    return 0;
}