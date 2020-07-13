#include <iosteam>
#include <string>
#include <queue>
using namespace std;

int idx(char req){
    return req - 'a';
}

int NoOfSubstrings(string input, int k){
    int ind[26];
    for(int i = 0; i < 26; i++) ind[i] = -1;
    int ans = 0, l = 0;
    dequeue <int> req;
    for(int i = 0; i < (int)input.size(); i++){
        if((int)req.size() == k) { 
            ans++; 
            ind[idx(input[l])] = -1;
            l++;
        }
        if(ind[idx(input[i])] != -1){
            while(ind[idx(input[i])] != req.front()) req.pop_front();
            req.pop_front();
        }
        req.push_back(input[i]);
        ind[idx(input[i])] = i;
    }


}


int main(){
    string input;
    int k;
    cout << NoOfSubstrings(input, k) << endl;
    return 0;
}