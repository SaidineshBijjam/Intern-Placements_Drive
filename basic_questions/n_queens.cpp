#include <iostream>

using namespace std;

#define sz(A) (int)A.size()

void search(int curr, int N, int **a, int *c, int *d1, int *d2){
  // Printing Output if configuration possible
  if(curr == N){
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        cout << a[i][j] << " ";
      }
      cout << '\n';
    }
    cout << '\n';
    return;
  }

  // curr indicates which row we are in
  // "c" indicates which columns are filled
  // "d1, d2" incdicates the diagonals
  for(int i = 0; i < N; i++){
  
    // This condition is used to keep the queen if there is no queen till now in that column or diagonals
    if(!c[i] && !d1[i + curr] && !d2[i - curr + N]){
      a[curr][i] = c[i] = d1[i + curr] = d2[i - curr + N] = 1;
      search(curr + 1, N, a, c, d1, d2);
      a[curr][i] = c[i] = d1[i + curr] = d2[i - curr + N] = 0;
    }
  }
  return;
}


int main(int argc, char const *argv[]) {
  int N, **a;
  cin >> N;
  a = (int **)malloc(N * sizeof(int *));
  for(int i = 0; i < N; i ++) {
    a[i] = (int *)malloc(N * sizeof(int));
  }
  int col[N], diag1[2 * N - 1], diag2[2 * N - 1];
  for(int i = 0; i < N; i++) col[i] = 0;
  for(int i = 0; i < 2 * N - 1; i++) diag1[i] = diag2[i] = 0;
  search(0, N, a, col, diag1, diag2);
  return 0;
}
