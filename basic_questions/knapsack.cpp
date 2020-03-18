#include <iostream>
#include <vector>

using namespace std;

#define sz(A) (int)A.size()


int main(){
    int N, input;
    cin >> N;

    vector <int> req, possible;
    for(int i = 0; i < N; i++){
        cin >> input;
        req.push_back(input);
    }

    int sum = 0;
    for(int i = 0; i < N; i++){
        sum += req[i];
    }

    for(int i = 0; i <= sum; i++){
        possible.push_back(0);
    }

    possible[0] = 1;

    for(int i = 0; i < N; i++){
        for(int j = sum; j >= 0; j--){
            if(sz(possible) > j + req[i] && possible[j]) possible[j + req[i]] = 1;
        }
    }

    for(int i = 0; i <= sum; i++){
        if(possible[i]) cout << i << " ";
    }
    cout << '\n';

    return 0;
}

