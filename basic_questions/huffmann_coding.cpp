#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

#define sz(A) (int)A.size()

typedef struct node {
    node *c1, *c2;
    int idx;
    int val;
    bool operator <(node P){
        if(val < P.val) return 1;
        else return 0;
    }
}node;

void dfs(node *root, vector <int> &curr){
    if(root->c1 == NULL && root->c2 == NULL){
        cout << root->idx << " : "; 
        for(int i = 0; i < sz(curr); i++) cout << curr[i]; cout << endl; 
    }else{
        curr.push_back(0);
        dfs(root->c1, curr);
        curr.push_back(1);
        dfs(root->c2, curr);
    }
    if(!curr.empty()) curr.pop_back();
    return;
}

int main(){
    int N; cin >> N;
    int count[26];
    for(int i = 0; i < 26; i++) count[i] = 0;
    for(int i = 0; i < N; i++) cin >> count[i];

    // Taking input using the given string 
    // string input;
    // cin >> input;
    // for(int i = 0; i < sz(input); i++){
    //     count[input[i] - 'a']++;
    // }

    map <int, node*> req; priority_queue < pair<int, int> > curr; 
    for(int i = 0; i < 26; i++){
        if(count[i] > 0){
            node *temp = (node *)malloc(sizeof(node));
            temp->c1 = temp->c2 = NULL; temp->val = count[i]; temp->idx = i;
            req[i] = temp;
            curr.push({-count[i], i});
        }
    }

    int idx = 26; node* root = NULL;
    while(!curr.empty()){
        pair <int, int> t1 = curr.top(); curr.pop();
        if(!curr.empty()){
            pair <int, int> t2 = curr.top();
            curr.pop();
            node *temp = (node *)malloc(sizeof(node));
            temp->val = -(t1.first + t2.first); temp->idx = idx++;
            temp->c1 = req[t1.second]; temp->c2 = req[t2.second];
            pair <int, int> t3 = {-temp->val, temp->idx}; 
            curr.push(t3); req[temp->idx] = temp;
            root = temp;
        } else root = req[t1.second];
    }
    
    vector <int> huffman;
    dfs(root, huffman);

    return 0;
}