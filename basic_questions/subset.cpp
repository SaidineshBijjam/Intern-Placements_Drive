#include <iostream>
#include <vector>

using namespace std;

#define sz(A) (int)A.size()


void generate_subset(int k, vector <int> subset){

  if(k == 0){
    for(int i = 0; i < sz(subset); i++) cout << subset[i] << " ";
    cout << '\n';
    return;
  }
  generate_subset(k - 1, subset);
  subset.push_back(k);
  generate_subset(k - 1, subset);
  subset.pop_back();
  return;
}



int main(int argc, char const *argv[]) {
  // make read and write faster
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  vector <int> subset;
  // recursive
  generate_subset(n, subset);

  // iterative
  for(int i = 0; i < (1 << n); i++){
    vector <int> subset_i;
    for(int j = 0; j < n; j++){
      if(i & (1 << j)) subset_i.push_back(j);
    }

    for(int j = 0; j < sz(subset_i); j++) cout << subset_i[j] << " ";
    cout << '\n';
  }

  return 0;
}
