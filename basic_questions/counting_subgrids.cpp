#include <iostream>

using namespace std;

#define sz(A) (int)A.size()


int main(){
    int r, c, ans ,temp;
    cin >> r >> c;

    int a[r][c];
    int count[r][c/32 + 1];

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++)
            cin >> a[i][j];
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < (c / 32) + 1; j++){
            count[i][j] = 0;
            for(int k = 0; k < 32 && j * 32 + k < c; k++){
                count[i][j] = (count[i][j] << 1) + a[i][j * 32 + k];
            }
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < (c / 32) + 1; j++){
            cout << count[i][j] << " ";
        }
        cout << endl;
    }

    ans = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < r; j++){
            temp = 0;
            for(int k = 0; k < (c / 32) + 1; k++){
                temp += __builtin_popcount(count[i][k] & count[j][k]);

            }
            cout << i << " " << j << " " << temp << endl;
            ans += (((temp) * (temp - 1)) / 2);
        }
    }

    cout << ans << endl;

    return 0;
}