#include <iostream>
#include <vector>

using namespace std;

#define sz(A) (int)A.size()

void generate_permutations(vector <int> p, vector <int> in, vector <int> choosen){
  if(sz(p) == sz(in)) {
    for(int i = 0; i < sz(in); i++){
      cout << p[i] << " ";
    }
    cout << '\n';
    return;
  }

  for(int i = 0; i < sz(in); i++){
    if(choosen[i]) continue;
    p.push_back(in[i]);
    choosen[i] = 1;
    generate_permutations(p, in, choosen);
    choosen[i] = 0;
    p.pop_back();
  }
  return;
}


int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n, x;
  vector <int> inputs, permutation;
  // taking input
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> x; inputs.push_back(x);
  }

  // recursive
  vector <int> choosen(n, 0);
  generate_permutations(permutation, inputs, choosen);
  return 0;
}
