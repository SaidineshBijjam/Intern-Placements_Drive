#include <iostream>

using namespace std;

#define sz(A) (int)A.size()

int algo(int row, int col, int count, int N, int **arr){
    int n = 0;
    // if(row < 0 || row > N - 1 || col < 0 || col > N - 1) return 0;
    // if(arr[row][col]) return 0;
    if(row == N - 1 && col == N - 1){
        if(count == N * N) n++;
        return n;
    }
    int l, r, u, d; l = r = u = d = 0;
    if(row + 1 <= N - 1 && !arr[row + 1][col]) d = 1;
    if(col + 1 <= N - 1 && !arr[row][col + 1]) r = 1;
    if(col - 1 >= 0 && !arr[row][col - 1]) l = 1;
    if(row - 1 >= 0 && !arr[row - 1][col]) u = 1;

    // Checking if we are able to cover all blocks or not
    // if((l&r) && !(u|d)) return 0;
    // if((u&d) && !(l|r)) return 0;

    // Moving Up Down Left Right
    arr[row][col] = 1;
    if(d) n += algo(row + 1, col, count + 1, N, arr);
    if(r) n += algo(row, col + 1, count + 1, N, arr);
    if(u) n += algo(row - 1, col, count + 1, N, arr);
    if(l) n += algo(row, col - 1, count + 1, N, arr);
    arr[row][col] = 0;
    return n;
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    // Creating an array
    int **arr = (int **)malloc(N * sizeof(int *));
    for(int i = 0; i < N; i++){
        arr[i] = (int *)malloc(N * sizeof(int));
    }
    // making all zero
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            arr[i][j] = 0;
        }
    }
    // algo one
    cout << algo(0, 0, 1, N, arr) << '\n';
    return 0;
}
